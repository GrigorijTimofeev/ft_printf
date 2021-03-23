/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:19:36 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 15:19:37 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	char			type;
}					t_flags;

void				ft_flags_parser(const char *format, t_flags *g_flags,
						int *i);
int					ft_width_parser(va_list argptr, const char *format,
						t_flags *g_flags, int *i);
int					ft_precision_parser(va_list argptr, const char *format,
						t_flags *g_flags, int *i);
int					ft_processor(t_flags *g_flags, va_list argptr);

#endif
