/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:00:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 11:39:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_decimal(t_spec_info *spec)
{
	if (spec->pad == '0' && spec->prec)
		spec->error = TRUE;
	spec->code = 'd';
}
