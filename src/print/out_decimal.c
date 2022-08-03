/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/02 21:52:03 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

static void	set_negative_prefix(t_param *spec, long *nbr);
static int justify_left(t_param *spec, char *string, int strlen);
static int justify_right(t_param *spec, char *string, int strlen);

int	out_decimal(t_param *spec, va_list args)
{
	long	nbr;
	char	*string;
	int		written;
	int		strlen;

	written = 0;
	nbr = va_arg(args, int);
	set_negative_prefix(spec, &nbr);
	string = itoa_base(nbr, DECIMAL);
	strlen = ft_strlen(string);
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
	if (spec->flags[LEFT])
		written += justify_left(spec, string, strlen);
	else
		written += justify_right(spec, string, strlen);
	free(string);
	return (written);
}

static int justify_left(t_param *spec, char *string, int strlen)
{
	int		written;
	int		temp;

	written = 0;
	if (spec->prefix)
		written += put_string(spec->prefix, spec->prefix_size);
	spec->width -= (strlen + spec->precision + spec->prefix_size);
	spec->pad = '0';
	if (spec->precision > 0)
	{
		temp = spec->width;
		spec->width = spec->precision;
		written += put_padding(spec);
		spec->width = temp;
	}
	spec->pad = ' ';
	written += put_string(string, strlen);
	written += put_padding(spec);
	return (written);
}

static int justify_right(t_param *spec, char *string, int strlen)
{
	int		written;

	written = 0;
	spec->width -= (strlen + spec->precision + spec->prefix_size);
	if (spec->pad == ' ')
		written += put_padding(spec);
	if (spec->prefix)
		written += put_string(spec->prefix, spec->prefix_size);
	spec->pad = '0';
	if (spec->precision > 0)
		spec->width = spec->precision;
	written += put_padding(spec);
	written += put_string(string, strlen);
	return (written);
}

static void	set_negative_prefix(t_param *spec, long *nbr)
{
	if (*nbr < 0)
	{
		spec->prefix = "-";
		spec->prefix_size = 1;
		*nbr *= (-1);
	}
}
