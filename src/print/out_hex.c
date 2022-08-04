/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:24:56 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 21:19:29 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

// XXX: Flags proibidas: ' ' '+'
// permitidas: '-' '0' largura precisão
void	set_unsigned_prefix(t_param *spec);
void	set_number_precision(t_param *spec, int strlen);

int	out_hex(t_param *spec, va_list args)
{
	unsigned int	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned int);
	// TODO: mover para uma função
	if (spec->code == 'x')
		string = itoa_base(nbr, LOWER_HEX);
	else
		string = itoa_base(nbr, UPPER_HEX);
	strlen = ft_strlen(string);

	if (!nbr && !spec->precision)
	{
		string[0] = 0;
		strlen = 0;
	}
	set_number_precision(spec, strlen);
	if (spec->prefix_size && nbr > 0)
		set_unsigned_prefix(spec);
	if (spec->flags[LEFT])
		written += left_justify(spec, string, strlen);
	else
		written += right_justify(spec, string, strlen);
	free(string);
	return (written);
}

void set_number_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

void	set_unsigned_prefix(t_param *spec)
{
	if (spec->code == 'x')
		spec->prefix = "0x";
	else if (spec->code == 'X')
		spec->prefix = "0X";
	else
		spec->prefix = "";
}
