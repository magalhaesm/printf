/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:29:41 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 18:15:24 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_percent(t_spec_info *spec, va_list args)
{
	(void) args;
	spec->prefix_size = 1;
	return (put_string(&spec->code, 1));
}
