/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:55:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/13 05:05:06 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	put_s(va_list args)
{
	char	*string;
	size_t	length;

	string = va_arg(args, char *);
	length = ft_strlen(string);
	write(STDOUT_FILENO, &string, length);
	return (length);
}
