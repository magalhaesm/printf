/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 22:25:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/printer.h"

// XXX: Flags proibidas: '+' ' ' '#' '0' precisão
// permitidas: '-' largura
void	p_set_unsigned_prefix(t_param *spec);
void	p_set_number_precision(t_param *spec, int strlen);
static int	justify_number(t_param *spec, char *string, int strlen);
static int	print_nil(t_param *spec);

int	out_pointer(t_param *spec, va_list args)
{
	unsigned long	nbr;
	char			*string;
	int				written;
	int				strlen;

	written = 0;
	nbr = va_arg(args, unsigned long);
	string = itoa_base(nbr, LOWER_HEX);
	if (!nbr)
	{
		free(string);
		return (print_nil(spec));
	}
	strlen = ft_strlen(string);
	p_set_number_precision(spec, strlen);
	if (spec->code == 'p')
	{
		spec->prefix = "0x";
		spec->prefix_size = 2;
	}
	written += justify_number(spec, string, strlen);
	free(string);
	return (written);
}

static int	justify_number(t_param *spec, char *string, int strlen)
{
	int		written;

	written = 0;
	if (spec->flags[LEFT])
		written += left_justify(spec, string, strlen);
	else
		written += right_justify(spec, string, strlen);
	return (written);
}

static int	print_nil(t_param *spec)
{
	char	*string;
	int		strlen;
	int		written;

	written = 0;
	string = "(nil)";
	strlen = 5;
	// TODO: pq isso???
	spec->width += (spec->prefix_size - 1);
	// spec->width += (strlen - 6);
	written += justify_number(spec, string, strlen);
	return (written);
}

void p_set_number_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

void	p_set_unsigned_prefix(t_param *spec)
{
	if (spec->code == 'x')
		spec->prefix = "0x";
	else if (spec->code == 'X')
		spec->prefix = "0X";
	else
		spec->prefix = "";
}
