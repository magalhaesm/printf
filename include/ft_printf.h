/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:24:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/23 18:02:29 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef enum e_bool {
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_spec_info {
	char		code;
	char		pad;
	t_bool		left;
	t_bool		sign;
	t_bool		space;
	t_bool		alt;
	t_bool		prec;
	t_bool		error;
	t_bool		is_negative;
	int			width;
	int			prec_size;
	int			pad_size;
	int			prefix_size;
	char		*hex_prefix;
	const char	*init;
	const char	*end;
	const char	*next;
}	t_spec_info;

int	ft_printf(const char *format, ...);

#endif
