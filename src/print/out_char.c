/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:31 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 22:37:11 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_char(t_param *spec, va_list args)
{
	char	chr;
	int		written;

	written = 0;
	chr = va_arg(args, int);
	spec->width -= 1;
	if (!spec->flags[LEFT])
		written += put_width(spec);
	written += put_string(&chr, 1);
	written += put_width(spec);
	return (written);
}
