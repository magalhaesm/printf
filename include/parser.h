/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:35:18 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 18:22:51 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_printf.h"

typedef void	(*t_flag)(t_spec_info *);

t_flag		*flag_array(void);
void		init_parser(void);
void		clean_info(t_spec_info *spec);
int			read_nbr(const char **format);
void		left_justify(t_spec_info *spec);
void		sign(t_spec_info *spec);
void		space(t_spec_info *spec);
void		hash(t_spec_info *spec);
void		left_pad(t_spec_info *spec);
void		parse_spec(const char *format, t_spec_info *spec);
const char	*find_spec(const char *format);

#endif
