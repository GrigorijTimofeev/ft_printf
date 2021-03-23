/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:26:04 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 14:26:05 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

void	ft_char_minus(int width, char ch)
{
	width--;
	ft_putchar_fd(ch, 1);
	while (width--)
		write(1, " ", 1);
}

void	ft_char_no_minus(int width, char ch)
{
	width--;
	while (width--)
		write(1, " ", 1);
	ft_putchar_fd(ch, 1);
}

int		ft_proc_char(t_flags *g_flags, va_list argptr)
{
	int		length;
	char	ch;

	ch = va_arg(argptr, int);
	length = g_flags->width;
	if (g_flags->width > 1 && g_flags->minus == 0)
		ft_char_no_minus(g_flags->width, ch);
	else if (g_flags->width > 1 && g_flags->minus == 1)
		ft_char_minus(g_flags->width, ch);
	else if (g_flags->width <= 1)
	{
		length = 1;
		ft_putchar_fd(ch, 1);
	}
	return (length);
}
