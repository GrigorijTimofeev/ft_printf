/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:19:17 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 17:19:18 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_precision_digit(t_flags *g_flags, const char *format, int *i)
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
	g_flags->precision = val;
	return (1);
}

void	ft_precision_star(va_list argptr, t_flags *g_flags, int *i)
{
	int		val;

	val = va_arg(argptr, int);
	if (val < 0)
		val = -1;
	g_flags->precision = val;
	*i = *i + 1;
}

int		ft_precision_parser(va_list argptr, const char *format,
			t_flags *g_flags, int *i)
{
	*i = *i + 1;
	g_flags->precision = 0;
	if (ft_isdigit(format[*i]))
	{
		if (ft_precision_digit(g_flags, format, i) == -1)
			return (-1);
	}
	else if (format[*i] == '*')
		ft_precision_star(argptr, g_flags, i);
	if (format[*i] != '%' && g_flags->precision != -1)
		g_flags->zero = 0;
	return (1);
}
