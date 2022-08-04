/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 23:26:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_unsigned(t_param *spec, va_list args)
{
	unsigned int	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned int);
	string = ft_itoa_base(nbr, DECIMAL);
	strlen = ft_strlen(string);
	if (!nbr && !spec->precision)
	{
		string[0] = 0;
		strlen = 0;
	}
	set_number_precision(spec, strlen);
	spec->prefix = "";
	spec->width += spec->prefix_size;
	written += put_number(spec, string, strlen);
	free(string);
	return (written);
}
