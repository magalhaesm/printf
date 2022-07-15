/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:24:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/07/14 17:53:59 by mdias-ma         ###   ########.fr       */
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
	t_bool		width;
	t_bool		prec;
	int			width_size;
	int			prec_size;
	t_bool		error;
	const char	*init;
	const char	*end;
	const char	*next;
}	t_spec_info;

int		ft_printf(const char *format, ...);

#endif
