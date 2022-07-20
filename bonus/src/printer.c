/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 20:19:15 by mdias-ma         ###   ########.fr       */
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
	{
		written++;
		write(STDOUT_FILENO, "0", 1);
	}
	return (written);
}

int	put_prefix(t_spec_info *spec)
{
	int	written;

	written = 0;
	if (spec->is_negative)
		written += put_string("-", 1);
	else if (spec->space)
		written += put_string(" ", 1);
	else if (spec->sign)
		written += put_string("+", 1);
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
	{
		written++;
		write(STDOUT_FILENO, " ", 1);
	}
	return (written);
}

int	put_format(t_spec_info *spec, va_list args)
{
	int	written;

	written = 0;
	if (spec->code == 'c')
		written = out_char(spec, args);
	else if (spec->code == 's')
		written = out_string(spec, args);
	else if (spec->code == 'p')
		written = out_pointer(spec, args);
	else if (spec->code == 'd')
		written = out_decimal(spec, args);
	else if (spec->code == 'i')
		written = out_decimal(spec, args);
	else if (spec->code == 'u')
		written = out_unsigned(spec, args);
	else if (spec->code == 'x')
		written = out_hex(spec, args);
	else if (spec->code == 'X')
		written = out_hex(spec, args);
	else if (spec->code == '%')
		written = out_percent(spec, args);
	return (written);
}
