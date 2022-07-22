/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 06:46:55 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:07:58 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_char(t_spec_info *spec)
{
	if (spec->pad == '0' || spec->sign || spec->space
		|| spec->alt || spec->prec)
		spec->error = TRUE;
}
