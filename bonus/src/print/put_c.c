/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:55:14 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/13 05:04:59 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	put_c(va_list args)
{
	char	chr;

	chr = va_arg(args, int);
	write(STDOUT_FILENO, &chr, 1);
	return (1);
}
