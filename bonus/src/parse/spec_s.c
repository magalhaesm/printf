/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 06:58:29 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 13:43:05 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	spec_string(t_spec_info *spec)
{
	if (spec->sign || spec->space || spec->alt)
		spec->error = TRUE;
	spec->code = 's';
}
