/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:01:05 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/15 13:04:23 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_integer(t_spec_info *spec)
{
	if (spec->alt || (spec->pad == '0' && spec->prec))
		spec->error = TRUE;
	spec->code = 'i';
}
