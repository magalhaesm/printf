/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-prs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:54:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 14:39:49 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_flag	*flag_array(void)
{
	static t_flag	array[128] = {NULL};

	return (array);
}

t_conv	*type_array(void)
{
	static t_conv	array[128] = {NULL};

	return (array);
}

void	init_parser(void)
{
	t_flag	*flags;
	t_conv	*types;

	flags = flag_array();
	flags['-'] = left_justify;
	flags['+'] = sign;
	flags[' '] = space;
	flags['#'] = hash;
	flags['0'] = left_pad;
	types = type_array();
	types['c'] = spec_char;
	types['s'] = spec_string;
	types['p'] = spec_pointer;
	types['d'] = spec_decimal;
	types['i'] = spec_integer;
	types['u'] = spec_unsigned;
	types['x'] = spec_lower_hex;
	types['X'] = spec_upper_hex;
	types['%'] = spec_percent;
}

void	clean_spec(t_spec_info *spec)
{
	spec->pad = ' ';
	spec->left = FALSE;
	spec->sign = FALSE;
	spec->space = FALSE;
	spec->alt = FALSE;
	spec->width = FALSE;
	spec->prec = FALSE;
	spec->prefix_size = 0;
	spec->is_positive = FALSE;
	spec->error = FALSE;
}

int	read_nbr(const char **format)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(**format))
	{
		nbr = (nbr * 10) + (**format - '0');
		(*format)++;
	}
	return (nbr);
}
