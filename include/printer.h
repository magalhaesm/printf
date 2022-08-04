/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:22:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 23:27:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "ft_printf.h"

# define DECIMAL "0123456789"
# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

typedef int	(*t_out)(t_param *, va_list);

int	debug(t_param *spec);

t_out	*conversion_array(void);
void	init_printer(void);
int		put_string(const char *string, int length);
int		put_number(t_param *spec, char *string, int strlen);
int		put_format(t_param *spec, va_list args);
int		put_padding(t_param *spec);
int		out_char(t_param *spec, va_list args);
int		out_string(t_param *spec, va_list args);
int		out_pointer(t_param *spec, va_list args);
int		out_decimal(t_param *spec, va_list args);
int		out_unsigned(t_param *spec, va_list args);
int		out_hex(t_param *spec, va_list args);
int		out_percent(t_param *spec, va_list args);
char	*ft_itoa_base(unsigned long nbr, char *nbr_sys);
int		nbrlen(unsigned long n, unsigned long base);
int		left_justify(t_param *spec, char *string, int strlen);
int		right_justify(t_param *spec, char *string, int strlen);
void	set_number_precision(t_param *spec, int strlen);
void	set_unsigned_prefix(t_param *spec);

#endif
