/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:28:36 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 23:20:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printer.h"

t_out	*conversion_array(void)
{
	static t_out	array[128] = {NULL};

	return (array);
}

void	init_printer(void)
{
	t_out	*types;

	types = conversion_array();
	types['c'] = out_char;
	types['s'] = out_string;
	types['p'] = out_pointer;
	types['d'] = out_decimal;
	types['i'] = out_decimal;
	types['u'] = out_unsigned;
	types['x'] = out_hex;
	types['X'] = out_hex;
	types['%'] = out_percent;
}

void	set_number_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

void	set_unsigned_prefix(t_param *spec)
{
	if (spec->code == 'x')
		spec->prefix = "0x";
	else if (spec->code == 'X')
		spec->prefix = "0X";
	else
		spec->prefix = "";
}
