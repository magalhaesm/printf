/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/04 14:31:08 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printer.h"

int	put_string(const char *string, int length)
{
	write(STDOUT_FILENO, string, length);
	return (length);
}

int	put_padding(t_param *spec)
{
	int	written;

	written = 0;
	while (spec->width > 0)
	{
		written += put_string(&spec->pad, 1);
		spec->width--;
	}
	return (written);
}

int	put_number_justified(t_param *spec, char *string, int strlen)
{
	int	written;

	written = 0;
	if (spec->flags[LEFT])
		written += left_justify(spec, string, strlen);
	else
		written += right_justify(spec, string, strlen);
	return (written);
}

int	put_format(t_param *spec, va_list args)
{
	t_out	*types;
	t_out	put_conversion;

	types = conversion_array();
	put_conversion = types[(unsigned)spec->code];
	if (!put_conversion)
		return (put_string(spec->init, (spec->end - spec->init)));
	return (put_conversion(spec, args));
}
