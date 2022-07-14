/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:54:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 17:15:13 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_flag	*flags_array(void)
{
	static t_flag	modifiers[128] = {NULL};

	return (modifiers);
}

t_conv	*conversions_array(void)
{
	static t_conv	modifiers[128] = {NULL};

	return (modifiers);
}

void	init_parser(void)
{
	t_flag	*flags;
	t_conv	*conversions;

	flags = flags_array();
	flags['-'] = justify_left;
	flags['+'] = sign;
	flags[' '] = space;
	flags['#'] = sharp;
	flags['0'] = left_pad;
	conversions = conversions_array();
	conversions['c'] = spec_char;
	conversions['s'] = spec_string;
	conversions['p'] = spec_pointer;
	conversions['d'] = spec_decimal;
	conversions['i'] = spec_integer;
	conversions['u'] = spec_unsigned_decimal;
	conversions['x'] = spec_lower_hex;
	conversions['X'] = spec_upper_hex;
	conversions['%'] = spec_percent;
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
