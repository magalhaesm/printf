/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 06:59:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:09:01 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_pointer(t_spec_info *spec)
{
	if (spec->sign || spec->space || spec->alt
		|| spec->prec || spec->pad == '0')
		spec->error = TRUE;
}
