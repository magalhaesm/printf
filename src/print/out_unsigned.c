/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/02 09:47:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

// XXX: Flags proibidas: '+' ' ' '#' precisão
// permitidas: '-' '0' largura
int	out_unsigned(t_param *spec, va_list args)
{
	unsigned int	nbr;
	char			*u_nbr;
	int				written;

	nbr = va_arg(args, unsigned int);
	u_nbr = itoa_base(nbr, DECIMAL);
	written = dispatcher(u_nbr, spec, ft_strlen(u_nbr));
	free(u_nbr);
	return (written);
}
