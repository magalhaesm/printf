/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:26 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 17:28:45 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/utils.h"

void	parse_spec(const char *format, t_spec_info *spec)
{
	clean_spec(spec);
	spec->init = format++;
	if (*format == '%')
	{
		spec->end = format + 1;
		format++;
		spec->next = find_spec(format);
		return ;
	}
	parse_flags(&format, spec);
	parse_width(&format, spec);
	parse_precision(&format, spec);
	parse_conversion(&format, spec);
	spec->end = format + 1;
	spec->next = find_spec(format);
}

void	parse_flags(const char **format, t_spec_info *spec)
{
	t_flag	*flags;
	t_flag	set_flag;

	flags = flags_array();
	set_flag = flags[(unsigned char)**format];
	if (!set_flag)
		return ;
	set_flag(spec);
	(*format)++;
	parse_flags(format, spec);
}

void	parse_width(const char **format, t_spec_info *spec)
{
	int	width;

	if(ft_isdigit(**format))
	{
		width = read_nbr(format);
		spec->width = TRUE;
		spec->width_size = width;
	}
}

void	parse_precision(const char **format, t_spec_info *spec)
{
	int precision;

	if (**format == '.')
	{
		(*format)++;
		precision = read_nbr(format);
		spec->prec = TRUE;
		spec->prec_size = precision;
	}
}

void	parse_conversion(const char **format, t_spec_info *spec)
{
	t_conv	*conversions;
	t_conv	set_conversion;

	conversions = conversions_array();
	set_conversion = conversions[(unsigned char)**format];
	if (!set_conversion)
	{
		spec->error = TRUE;
		return ;
	}
	set_conversion(spec);
}
