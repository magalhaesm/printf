/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 14:46:24 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

// XXX: Flags proibidas: '+' ' ' '#' precisão
// permitidas: '-' '0' largura
int	out_unsigned(t_param *spec, va_list args)
{
	unsigned int	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned int);
	string = itoa_base(nbr, DECIMAL);
	strlen = ft_strlen(string);

	if (!nbr && !spec->precision)
	{
		string[0] = 0;
		strlen = 0;
	}
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
	// TODO: set_unsigned_prefix
	spec->prefix = "";
	spec->width += spec->prefix_size;
	if (spec->flags[LEFT])
		written += left_justify(spec, string, strlen);
	else
		written += right_justify(spec, string, strlen);
	free(string);
	return (written);
}
