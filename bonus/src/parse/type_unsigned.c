/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:01:41 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 17:23:59 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_unsigned(t_spec_info *spec)
{
	if (spec->sign || spec->space || spec->alt || spec->pad == '0')
		spec->error = TRUE;
	spec->code = 'u';
}
