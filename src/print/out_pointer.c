/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 23:19:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

static int	print_nil(t_param *spec);

int	out_pointer(t_param *spec, va_list args)
{
	unsigned long	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned long);
	string = ft_itoa_base(nbr, LOWER_HEX);
	if (!nbr)
	{
		free(string);
		return (print_nil(spec));
	}
	strlen = ft_strlen(string);
	set_number_precision(spec, strlen);
	if (spec->code == 'p')
	{
		spec->prefix = "0x";
		spec->prefix_size = 2;
	}
	written += put_number(spec, string, strlen);
	free(string);
	return (written);
}

static int	print_nil(t_param *spec)
{
	char	*string;
	int		strlen;
	int		written;

	written = 0;
	string = "(nil)";
	strlen = 5;
	// TODO: revisar isso!
	spec->width += (spec->prefix_size - 1);
	written += put_number(spec, string, strlen);
	return (written);
}
