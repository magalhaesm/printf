/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:09:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:08:58 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_percent(t_spec_info *spec)
{
	if (spec->pad == '0' || spec->left || spec->space || spec->sign
		|| spec->prec || spec->width || spec->alt)
		spec->error = TRUE;
}
