/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:24:56 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 18:13:40 by mdias-ma         ###   ########.fr       */
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
	u_nbr = ux_toa(nbr, LOWER_HEX);
	spec->prefix_size = has_prefix(spec);
	written = dispatcher(u_nbr, spec, ft_strlen(u_nbr));
	free(u_nbr);
	return (written);
}
