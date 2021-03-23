/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:49:01 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 17:49:02 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

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

int					ft_count_16(unsigned long val);
void				ft_get_str_x_big(unsigned long val, char *str, int length);
void				ft_get_str_x(unsigned long val, char *str, int length);
int					ft_proc_dec(t_flags *g_flags, va_list argptr);
int					ft_proc_char(t_flags *g_flags, va_list argptr);
int					ft_proc_string(t_flags *g_flags, va_list argptr);
int					ft_proc_unsigned(t_flags *g_flags, va_list argptr);
int					ft_proc_dec_uns(t_flags *g_flags, char *str);
int					ft_proc_x_big(t_flags *g_flags, va_list argptr, int length);
int					ft_proc_x(t_flags *g_flags, va_list argptr, int length);
int					ft_proc_ptr(t_flags *g_flags, va_list argptr);
char				*ft_width(char *str_temp, t_flags *g_flags);
int					ft_proc_percent(t_flags *g_flags);
char				*ft_chcek_get_empty_string_and_free(char *str,
						int precision);

#endif
