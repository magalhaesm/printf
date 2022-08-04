/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:24:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/03 22:44:11 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft/libft.h"

typedef enum e_bool {
	FALSE, TRUE
}	t_bool;

typedef enum e_flags {
	LEFT, ZERO, SIGN, SPACE, HASH
}	t_flags;

typedef struct s_param {
	char		code;
	char		pad;
	int			width;
	int			prec_size;
	int			precision;
	int			prefix_size;
	char		*prefix;
	t_bool		flags[5];
	const char	*init;
	const char	*end;
	const char	*next;
}	t_param;

int	ft_printf(const char *format, ...);

#endif
