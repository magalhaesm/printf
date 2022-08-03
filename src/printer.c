/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 13:25:30 by mdias-ma         ###   ########.fr       */
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

// XXX: remover!
int	put_prefix(t_param *spec)
{
	int	written;

	written = 0;
	if (spec->prefix)
		written += put_string(spec->prefix, spec->prefix_size);
	if (spec->pad == '0')
		written += put_padding(spec);
	return (written);
}

// XXX: remover!
int	put_width(t_param *spec)
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

#include <stdio.h>
int	debug(t_param *spec)
// int	put_format(t_param *spec, va_list args)
{
	// (void) args;
	printf("\n\nconversão: %c\n", spec->code);
	printf("largura: %d\n", spec->width);
	printf("precisão: %d\n", spec->precision);
	printf("justicar: %d\n", spec->flags[LEFT]);
	printf("preencher: %d\n", spec->flags[ZERO]);
	printf("sinal: %d\n", spec->flags[SIGN]);
	printf("espaço: %d\n", spec->flags[SPACE]);
	printf("hash: %d\n", spec->flags[HASH]);
	printf("prefixo: %s\n", spec->prefix);
	// for (int i = 0; i < NARGS; i++)
	// 	printf("flags: %d: %d\n", i, spec->flags[i]);
	return (0);
}

// int	put_format(t_param *spec, va_list args)
// {
// 	t_out	*types;
// 	t_out	put_conversion;
// 	int		written;
//
// 	written = 0;
// 	types = conversion_array();
// 	put_conversion = types[(unsigned)spec->code];
// 	if (!put_conversion)
// 		return (put_string(spec->init, (spec->end - spec->init)));
// 	written = put_conversion(spec, args);
// 	debug(spec);
// 	return (written);
// }
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
