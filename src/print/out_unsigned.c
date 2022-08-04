/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/04 09:42:03 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

static char	*to_string(t_param *spec, unsigned int nbr);
static void	set_unsigned_prefix(t_param *spec);

int	out_unsigned(t_param *spec, va_list args)
{
	unsigned long	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned int);
	string = to_string(spec, nbr);
	if (nbr == 0 && spec->precision == 0)
		string[0] = 0;
	strlen = ft_strlen(string);
	set_number_precision(spec, strlen);
	if (spec->prefix_size && nbr > 0)
		set_unsigned_prefix(spec);
	written += put_number(spec, string, strlen);
	free(string);
	return (written);
}

static char	*to_string(t_param *spec, unsigned int nbr)
{
	char	*string;

	if (spec->code == 'u')
		string = ft_itoa_base(nbr, DECIMAL);
	else if (spec->code == 'x')
		string = ft_itoa_base(nbr, LOWER_HEX);
	else
		string = ft_itoa_base(nbr, UPPER_HEX);
	return (string);
}

static void	set_unsigned_prefix(t_param *spec)
{
	if (spec->code == 'x')
		spec->prefix = "0x";
	else if (spec->code == 'X')
		spec->prefix = "0X";
}
