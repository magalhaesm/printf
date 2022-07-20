/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 20:23:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"
#include <stdio.h>

int	out_decimal(t_spec_info *spec, va_list args)
{
	long	nbr;
	char	*decimal;
	int		written;

	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		spec->is_negative = TRUE;
		nbr *= (-1);
	}
	spec->prefix_size = has_prefix(spec);
	decimal = uxtoa(nbr, DECIMAL);
	written = dispatcher(decimal, spec, ft_strlen(decimal));
	free(decimal);
	return (written);
}
