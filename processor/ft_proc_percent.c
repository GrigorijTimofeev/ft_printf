/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:56:55 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 17:57:00 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_width_perc(t_flags *g_flags)
{
	int		length;
	int		width;

	length = 1;
	width = g_flags->width;
	if (g_flags->minus == 1)
	{
		ft_putchar_fd('%', 1);
		while (--width)
		{
			length++;
			ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		while (--width)
		{
			length++;
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('%', 1);
	}
	return (length);
}

int		ft_width_zero_perc(int width)
{
	int		length;

	length = 1;
	while (--width)
	{
		length++;
		ft_putchar_fd('0', 1);
	}
	ft_putchar_fd('%', 1);
	return (length);
}

int		ft_proc_percent(t_flags *g_flags)
{
	int		length;

	length = 0;
	if (g_flags->width > 0)
	{
		if (g_flags->zero == 1)
			length = ft_width_zero_perc(g_flags->width);
		else if (g_flags->zero == 0)
			length = ft_width_perc(g_flags);
	}
	else
	{
		length = 1;
		ft_putchar_fd('%', 1);
	}
	return (length);
}
