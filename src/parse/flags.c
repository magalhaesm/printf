/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/18 10:50:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	left_justify(t_spec_info *spec)
{
	if (spec->left || spec->pad == '0')
		spec->error = TRUE;
	spec->left = TRUE;
	spec->pad = ' ';
}

void	sign(t_spec_info *spec)
{
	if (spec->space || spec->sign)
		spec->error = TRUE;
	spec->sign = TRUE;
}

void	space(t_spec_info *spec)
{
	if (spec->sign || spec->space)
		spec->error = TRUE;
	spec->space = TRUE;
}

void	hash(t_spec_info *spec)
{
	spec->alt = TRUE;
}

void	left_pad(t_spec_info *spec)
{
	if (spec->left || spec->pad == '0')
		spec->error = TRUE;
	spec->pad = '0';
}
