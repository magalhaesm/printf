/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_upper_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:05:08 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 20:23:18 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_upper_hex(t_spec_info *spec)
{
	if (spec->sign || spec->space)
		spec->error = TRUE;
	spec->code = 'X';
}
