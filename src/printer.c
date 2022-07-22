/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/22 20:04:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printer.h"

int	put_string(const char *string, int length)
{
	write(STDOUT_FILENO, string, length);
	return (length);
}

int	put_padding(t_spec_info *spec)
{
	int	written;

	written = 0;
	while (spec->pad_size-- > 0)
		written += put_string(ZERO, 1);
	return (written);
}

int	put_prefix(t_spec_info *spec)
{
	int	written;

	written = 0;
	if (spec->is_negative)
		written += put_string(MINUS, 1);
	else if (spec->space)
		written += put_string(SPACE, 1);
	else if (spec->sign)
		written += put_string(PLUS, 1);
	else if (spec->alt)
		written += put_string(spec->hex_prefix, 2);
	if (spec->pad == '0')
		written += put_padding(spec);
	else if (spec->prec)
		written += put_padding(spec);
	return (written);
}

int	put_width(t_spec_info *spec)
{
	int	written;

	written = 0;
	if (spec->pad == '0')
	{
		spec->pad_size = spec->width;
		return (written);
	}
	while (spec->width-- > 0)
		written += put_string(SPACE, 1);
	return (written);
}

int	put_format(t_spec_info *spec, va_list args)
{
	t_out	*types;
	t_out	out_type;

	types = conversion_array();
	out_type = types[(unsigned)spec->code];
	if (!out_type)
		return (0);
	return (out_type(spec, args));
}
