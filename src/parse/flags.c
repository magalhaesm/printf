/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/04 13:29:27 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	left(t_param *spec)
{
	spec->flags[LEFT] = TRUE;
	spec->flags[ZERO] = FALSE;
	spec->pad = ' ';
}

void	padding(t_param *spec)
{
	if (spec->flags[LEFT])
		return ;
	spec->flags[ZERO] = TRUE;
	spec->pad = '0';
}

void	showsign(t_param *spec)
{
	spec->flags[PLUS] = TRUE;
	spec->flags[SPACE] = FALSE;
	spec->prefix = "+";
	spec->prefix_len = 1;
}

void	space(t_param *spec)
{
	if (spec->flags[PLUS])
		return ;
	spec->flags[SPACE] = TRUE;
	spec->prefix = " ";
	spec->prefix_len = 1;
}

void	hash(t_param *spec)
{
	spec->flags[HASH] = TRUE;
}
