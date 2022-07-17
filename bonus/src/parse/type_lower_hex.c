/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lower_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:04:27 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 17:50:05 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_lower_hex(t_spec_info *spec)
{
	if (spec->sign || spec->space)
		spec->error = TRUE;
	spec->code = 'x';
}
