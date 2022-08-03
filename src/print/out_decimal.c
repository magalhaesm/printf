/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 14:41:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

static void	set_signed_prefix(t_param *spec, long *nbr);
static void	set_precision(t_param *spec, int strlen);

int	out_decimal(t_param *spec, va_list args)
{
	long	nbr;
	char	*string;
	int		written;
	int		strlen;

	written = 0;
	nbr = va_arg(args, int);
	set_signed_prefix(spec, &nbr);
	string = itoa_base(nbr, DECIMAL);
	if (!nbr && !spec->precision)
		string[0] = 0;
	strlen = ft_strlen(string);
	set_precision(spec, strlen);
	if (spec->flags[LEFT])
		written += left_justify(spec, string, strlen);
	else
		written += right_justify(spec, string, strlen);
	free(string);
	return (written);
}

static void set_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

static void	set_signed_prefix(t_param *spec, long *nbr)
{
	if (*nbr < 0)
	{
		spec->prefix = "-";
		spec->prefix_size = 1;
		*nbr *= (-1);
	}
}
