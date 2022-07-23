/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:24:56 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 18:49:45 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_hex(t_spec_info *spec, va_list args)
{
	unsigned int	nbr;
	char			*u_nbr;
	int				written;

	nbr = va_arg(args, unsigned int);
	if (!nbr)
		spec->alt = FALSE;
	if (spec->code == 'X')
	{
		spec->hex_prefix = "0X";
		u_nbr = uxtoa(nbr, UPPER_HEX);
	}
	else
		u_nbr = uxtoa(nbr, LOWER_HEX);
	written = dispatcher(u_nbr, spec, ft_strlen(u_nbr));
	free(u_nbr);
	return (written);
}
