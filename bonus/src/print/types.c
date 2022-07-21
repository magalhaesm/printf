/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:28:36 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:52:06 by mdias-ma         ###   ########.fr       */
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
