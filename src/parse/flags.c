/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 13:55:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	left(t_param *spec)
{
	spec->flags[LEFT] = TRUE;
	spec->flags[ZERO] = FALSE;
	spec->pad = ' ';
}

void	sign(t_param *spec)
{
	spec->flags[SIGN] = TRUE;
	spec->flags[SPACE] = FALSE;
	spec->prefix = "+";
	spec->prefix_size = 1;
}

void	space(t_param *spec)
{
	if (spec->flags[SIGN])
		return ;
	spec->flags[SPACE] = TRUE;
	spec->prefix = " ";
	spec->prefix_size = 1;
}

void	hash(t_param *spec)
{
	spec->flags[HASH] = TRUE;
	spec->prefix = "0x";
	spec->prefix_size = 2;
}

void	padding(t_param *spec)
{
	if (spec->flags[LEFT])
		return ;
	spec->flags[ZERO] = TRUE;
	spec->pad = '0';
}
