/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-prt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:50:15 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

char	*uxtoa(unsigned long nbr, char *nbr_sys)
{
	char	*str;
	int		len;
	int		base;

	base = ft_strlen(nbr_sys);
	len = nbr_len(nbr, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nbr_sys[nbr % base];
		nbr /= base;
	}
	return (str);
}

int	nbr_len(unsigned long n, unsigned long base)
{
	if (n < base)
		return (1);
	n /= base;
	return (nbr_len(n, base) + 1);
}

int	dispatcher(char *string, t_spec_info *spec, int length)
{
	int	written;

	written = 0;
	if (spec->prec)
		spec->pad_size = spec->prec_size - length;
	if (spec->prec_size < length)
		spec->width -= length;
	else
		spec->width -= spec->prec_size;
	spec->width -= spec->prefix_size;
	if (spec->left)
	{
		written += put_prefix(spec);
		written += put_string(string, length);
		written += put_width(spec);
		return (written);
	}
	written += put_width(spec);
	written += put_prefix(spec);
	written += put_string(string, length);
	return (written);
}

int	has_prefix(t_spec_info *spec)
{
	if (spec->is_negative)
		return (1);
	if (spec->space)
		return (1);
	else if (spec->sign)
		return (1);
	else if (spec->alt)
		return (2);
	return (0);
}
