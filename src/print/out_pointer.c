/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/02 09:47:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

// XXX: Flags proibidas: '+' ' ' '#' '0' precisão
// permitidas: '-' largura
int	out_pointer(t_param *spec, va_list args)
{
	unsigned long	address;
	char			*hex;
	int				written;

	address = va_arg(args, unsigned long);
	if (!address)
	{
		hex = "(nil)";
		return (dispatcher(hex, spec, ft_strlen(hex)));
	}
	hex = itoa_base(address, LOWER_HEX);
	if (!hex)
		return (0);
	spec->alt = TRUE;
	spec->prefix_size = 2;
	written = dispatcher(hex, spec, ft_strlen(hex));
	free(hex);
	return (written);
}
