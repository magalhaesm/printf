/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:35:18 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/15 12:57:03 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_printf.h"

typedef void	(*t_flag)(t_spec_info *);
typedef void	(*t_conv)(t_spec_info *);

t_flag	*flag_array(void);
t_conv	*type_array(void);
void	init_parser(void);
void	clean_spec(t_spec_info *spec);
int		read_nbr(const char **format);
void	left_justify(t_spec_info *spec);
void	sign(t_spec_info *spec);
void	space(t_spec_info *spec);
void	hash(t_spec_info *spec);
void	left_pad(t_spec_info *spec);
void	spec_char(t_spec_info *spec);
void	spec_string(t_spec_info *spec);
void	spec_pointer(t_spec_info *spec);
void	spec_decimal(t_spec_info *spec);
void	spec_integer(t_spec_info *spec);
void	spec_unsigned(t_spec_info *spec);
void	spec_lower_hex(t_spec_info *spec);
void	spec_upper_hex(t_spec_info *spec);
void	spec_percent(t_spec_info *spec);
void	parse_spec(const char *format, t_spec_info *spec);
void	parse_flags(const char **format, t_spec_info *spec);
void	parse_width(const char **format, t_spec_info *spec);
void	parse_precision(const char **format, t_spec_info *spec);
void	parse_type(const char **format, t_spec_info *spec);

#endif
