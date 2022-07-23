/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:54:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 18:30:50 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_flag	*flag_array(void)
{
	static t_flag	array[128] = {NULL};

	return (array);
}

void	init_parser(void)
{
	t_flag	*flags;

	flags = flag_array();
	flags['-'] = left_justify;
	flags['+'] = sign;
	flags[' '] = space;
	flags['#'] = hash;
	flags['0'] = left_pad;
}

void	clean_info(t_spec_info *spec)
{
	spec->pad = ' ';
	spec->pad_size = 0;
	spec->left = FALSE;
	spec->sign = FALSE;
	spec->space = FALSE;
	spec->alt = FALSE;
	spec->width = 0;
	spec->prec = FALSE;
	spec->prec_size = 0;
	spec->prefix_size = 0;
	spec->is_negative = FALSE;
	spec->hex_prefix = "0x";
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
