/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/04 13:24:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

char	*ft_itoa_base(unsigned long nbr, char *nbr_sys)
{
	char	*str;
	int		len;
	int		base;

	base = ft_strlen(nbr_sys);
	len = nbrlen(nbr, base);
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

int	nbrlen(unsigned long n, unsigned long base)
{
	if (n < base)
		return (1);
	n /= base;
	return (nbrlen(n, base) + 1);
}

void	set_number_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

int	left_justify(t_param *spec, char *string, int strlen)
{
	int		written;
	int		temp;

	written = 0;
	if (spec->prefix[0])
		written += put_string(spec->prefix, spec->prefix_len);
	spec->width -= (strlen + spec->precision + spec->prefix_len);
	spec->pad = '0';
	if (spec->precision > 0)
	{
		temp = spec->width;
		spec->width = spec->precision;
		written += put_padding(spec);
		spec->width = temp;
	}
	spec->pad = ' ';
	written += put_string(string, strlen);
	written += put_padding(spec);
	return (written);
}

int	right_justify(t_param *spec, char *string, int strlen)
{
	int		written;

	written = 0;
	spec->width -= (strlen + spec->precision + spec->prefix_len);
	if (!spec->flags[ZERO])
	{
		spec->pad = ' ';
		written += put_padding(spec);
	}
	if (spec->prefix[0])
		written += put_string(spec->prefix, spec->prefix_len);
	spec->pad = '0';
	if (spec->width < spec->precision)
		spec->width = spec->precision;
	written += put_padding(spec);
	written += put_string(string, strlen);
	return (written);
}
