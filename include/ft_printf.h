/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:24:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/02 15:51:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft/libft.h"

# define NARGS 5

typedef enum e_bool {
	FALSE, TRUE
}	t_bool;

typedef enum e_flags {
	LEFT, PADDING, SIGN, SPACE, HASH
}	t_flags;

typedef struct s_param {
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
	int			pad_size;
	int			prec_size;
	int			precision;
	int			prefix_size;
	char		*prefix;
	char		*hex_prefix;
	t_bool		flags[NARGS];
	const char	*init;
	const char	*end;
	const char	*next;
}	t_param;

int	ft_printf(const char *format, ...);

#endif
