/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:46 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 19:30:06 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

int	out_string(t_spec_info *spec, va_list args)
{
	char	*string;
	int		strlen;

	string = va_arg(args, char *);
	if (!string)
	{
		string = "(null)";
		return (put_string(string, 6));
	}
	strlen = ft_strlen(string);
	if (!strlen && spec->prec)
		return (put_string("", 0));
	if (spec->space && !spec->width)
		spec->space = FALSE;
	if (spec->left)
		return (dispatcher(string, spec, strlen));
	if (spec->prec && spec->prec_size < strlen)
		strlen = spec->prec_size;
	else
		spec->prec = FALSE;
	return (dispatcher(string, spec, strlen));
}
