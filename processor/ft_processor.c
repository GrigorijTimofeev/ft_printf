/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:40:18 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 09:40:24 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_processor(t_flags *g_flags, va_list argptr)
{
	int		length;

	length = 0;
	if (g_flags->type == 'd' || g_flags->type == 'i')
		length = ft_proc_dec(g_flags, argptr);
	else if (g_flags->type == 'c')
		length = ft_proc_char(g_flags, argptr);
	else if (g_flags->type == 's')
		length = ft_proc_string(g_flags, argptr);
	else if (g_flags->type == 'u')
		length = ft_proc_unsigned(g_flags, argptr);
	else if (g_flags->type == 'X')
		length = ft_proc_x_big(g_flags, argptr, 0);
	else if (g_flags->type == 'x')
		length = ft_proc_x(g_flags, argptr, 0);
	else if (g_flags->type == 'p')
		length = ft_proc_ptr(g_flags, argptr);
	else if (g_flags->type == '%')
		length = ft_proc_percent(g_flags);
	return (length);
}
