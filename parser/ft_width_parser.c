/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:18:06 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 17:18:07 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_width_digit(t_flags *g_flags, const char *format, int *i)
{
	int		i_start;
	int		length;
	char	*str;
	int		val;

	i_start = *i;
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	length = *i - i_start;
	str = ft_substr(format, i_start, length);
	if (!str)
		return (-1);
	val = ft_atoi(str);
	free(str);
	g_flags->width = val;
	return (1);
}

void	ft_width_star(va_list argptr, t_flags *g_flags, int *i)
{
	int		val;

	val = va_arg(argptr, int);
	if (val < 0)
	{
		val *= -1;
		g_flags->minus = 1;
		g_flags->zero = 0;
	}
	g_flags->width = val;
	*i = *i + 1;
}

int		ft_width_parser(va_list argptr, const char *format,
			t_flags *g_flags, int *i)
{
	if (ft_isdigit(format[*i]))
	{
		if (ft_width_digit(g_flags, format, i) == -1)
			return (-1);
	}
	else if (format[*i] == '*')
		ft_width_star(argptr, g_flags, i);
	return (1);
}
