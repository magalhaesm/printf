/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 18:45:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	left_justify(t_spec_info *spec)
{
	spec->left = TRUE;
	spec->pad = ' ';
}

void	sign(t_spec_info *spec)
{
	spec->sign = TRUE;
	spec->prefix_size = 1;
}

void	space(t_spec_info *spec)
{
	spec->space = TRUE;
	spec->prefix_size = 1;
}

void	hash(t_spec_info *spec)
{
	spec->alt = TRUE;
	spec->prefix_size = 2;
}

void	left_pad(t_spec_info *spec)
{
	spec->pad = '0';
}
