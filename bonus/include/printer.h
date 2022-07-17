/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:22:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/17 18:16:10 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "ft_printf.h"

# define DECIMAL "0123456789"
# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int		put_string(const char *string, int length);
int		put_format(t_spec_info *spec, va_list args);
void	put_error(t_spec_info *spec);
int		put_prefix(t_spec_info *spec);
int		put_padding(t_spec_info *spec);
int		put_width(t_spec_info *spec, int length);
int		dispatcher(char *string, t_spec_info *spec, int length);
int		out_char(t_spec_info *spec, va_list args);
int		out_string(t_spec_info *spec, va_list args);
int		out_pointer(t_spec_info *spec, va_list args);
int		out_decimal(t_spec_info *spec, va_list args);
int		out_unsigned(t_spec_info *spec, va_list args);
int		out_hex(t_spec_info *spec, va_list args);
char	*ux_toa(unsigned long nbr, char *nbr_sys);
int		nbr_len(unsigned long n, unsigned long base);
int		has_prefix(t_spec_info *spec);

#endif
