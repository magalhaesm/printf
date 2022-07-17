/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 14:03:26 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_string(t_spec_info *spec, va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (!string)
	{
		string = "(null)";
		return (dispatcher(string, spec, ft_strlen(string)));
	}
	return (dispatcher(string, spec, ft_strlen(string)));
}
