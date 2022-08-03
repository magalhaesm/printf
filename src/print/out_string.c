/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 20:39:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

static int	print_null(t_param *spec);
static int	justfify_string(t_param *spec, char *string, int strlen);

int	out_string(t_param *spec, va_list args)
{
	char	*string;
	int		strlen;
	int		written;

	written = 0;
	string = va_arg(args, char *);
	if (string == NULL)
		return (print_null(spec));
	strlen = ft_strlen(string);
	if (spec->precision != -1 && spec->precision < strlen)
		strlen = spec->precision;
	spec->width -= strlen;
	written += justfify_string(spec, string, strlen);
	return (written);
}

static int	justfify_string(t_param *spec, char *string, int strlen)
{
	int		written;

	written = 0;
	if (spec->flags[LEFT])
	{
		written += put_string(string, strlen);
		written += put_padding(spec);
	}
	else
	{
		written += put_padding(spec);
		written += put_string(string, strlen);
	}
	return (written);
}

static int	print_null(t_param *spec)
{
	char	*string;
	int		strlen;
	int		written;

	written = 0;
	string = "(null)";
	strlen = 6;
	spec->width -= strlen;
	if (spec->precision == -1 || spec->precision >= strlen)
		written += justfify_string(spec, string, strlen);
	else
		written += put_string("", 0);
	return (written);
}
