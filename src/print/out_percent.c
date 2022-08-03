/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:29:41 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/02 09:47:06 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_percent(t_param *spec, va_list args)
{
	(void) args;
	return (put_string(&spec->code, 1));
}
