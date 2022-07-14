/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 06:59:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 13:48:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_pointer(t_spec_info *spec)
{
	if (spec->sign || spec->space || spec->alt || spec->prec)
		spec->error = TRUE;
	spec->code = 'p';
}
