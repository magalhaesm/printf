/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:26 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/20 21:58:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/utils.h"

static void	parse_flags(const char **format, t_spec_info *spec);
static void	parse_width(const char **format, t_spec_info *spec);
static void	parse_precision(const char **format, t_spec_info *spec);
static void	parse_type(const char **format, t_spec_info *spec);

void	parse_spec(const char *format, t_spec_info *spec)
{
	clean_spec(spec);
	spec->init = format++;
	parse_flags(&format, spec);
	parse_width(&format, spec);
	parse_precision(&format, spec);
	parse_type(&format, spec);
	spec->end = format + 1;
	spec->next = find_spec(spec->end);
}

static void	parse_flags(const char **format, t_spec_info *spec)
{
	t_flag	*flags;
	t_flag	set_flag;

	flags = flag_array();
	set_flag = flags[(unsigned)**format];
	if (!set_flag)
		return ;
	set_flag(spec);
	(*format)++;
	parse_flags(format, spec);
}

static void	parse_width(const char **format, t_spec_info *spec)
{
	if (ft_isdigit(**format))
		spec->width = read_nbr(format);
}

static void	parse_precision(const char **format, t_spec_info *spec)
{
	if (**format == '.')
	{
		(*format)++;
		spec->prec = TRUE;
		spec->prec_size = read_nbr(format);
	}
}

static void	parse_type(const char **format, t_spec_info *spec)
{
	t_conv	*types;
	t_conv	set_type;

	types = type_array();
	set_type = types[(unsigned)**format];
	if (!set_type)
		return ;
	spec->code = **format;
	set_type(spec);
}
