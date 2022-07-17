/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 18:16:53 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printer.h"
#include <stdio.h>

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
	if (spec->space && spec->is_positive)
		written += put_string(" ", 1);
	else if (spec->sign && spec->is_positive)
		written += put_string("+", 1);
	else if (spec->alt)
		written += put_string("0x", 2);
	if (spec->prec)
		written += put_padding(spec);
	return (written);
}

int	put_width(t_spec_info *spec, int length)
{
	int	written;

	written = 0;
	if (spec->prec_size < length)
		spec->width -= length;
	else
		spec->width -= spec->prec_size;
	spec->width -= spec->prefix_size;
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
	if (spec->error)
		put_error(spec);
	else
	{
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
	}
	return (written);
}
