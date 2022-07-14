/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_upper_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:05:08 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 13:57:39 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_upper_hex(t_spec_info *spec)
{
	if (spec->sign || spec->space)
		spec->error = TRUE;
	spec->code = 'H';
}
