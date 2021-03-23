/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:18:32 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 15:18:34 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_flags		g_flags;

void	ft_init_flags(void)
{
	g_flags.minus = 0;
	g_flags.zero = 0;
	g_flags.width = 0;
	g_flags.precision = -1;
	g_flags.type = 0;
}

int		ft_parser(va_list argptr, const char *format, int *i)
{
	ft_init_flags();
	*i = *i + 1;
	if (format[*i] == '-' || format[*i] == '0')
		ft_flags_parser(format, &g_flags, i);
	if (ft_isdigit(format[*i]) || format[*i] == '*')
		if (ft_width_parser(argptr, format, &g_flags, i) == -1)
			return (-1);
	if (format[*i] == '.')
		if (ft_precision_parser(argptr, format, &g_flags, i) == -1)
			return (-1);
	if (ft_strchr("cspdiuxX%", format[*i]) != NULL)
	{
		g_flags.type = format[*i];
		*i = *i + 1;
	}
	else
		return (0);
	return (ft_processor(&g_flags, argptr));
}
