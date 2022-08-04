/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:24:56 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 23:17:04 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

void	set_unsigned_prefix(t_param *spec);

int	out_hex(t_param *spec, va_list args)
{
	unsigned int	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned int);
	if (spec->code == 'x')
		string = ft_itoa_base(nbr, LOWER_HEX);
	else
		string = ft_itoa_base(nbr, UPPER_HEX);
	strlen = ft_strlen(string);
	if (!nbr && !spec->precision)
	{
		string[0] = 0;
		strlen = 0;
	}
	set_number_precision(spec, strlen);
	if (spec->prefix_size && nbr > 0)
		set_unsigned_prefix(spec);
	written += put_number(spec, string, strlen);
	free(string);
	return (written);
}
