/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:17:37 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/08 17:17:39 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_flags_parser(const char *format, t_flags *g_flags, int *i)
{
	if (format[*i] == '0')
	{
		while (format[*i] == '0')
			*i = *i + 1;
		g_flags->zero = 1;
	}
	if (format[*i] == '-')
	{
		while (format[*i] == '-')
			*i = *i + 1;
		g_flags->minus = 1;
	}
	if (format[*i] == '0')
	{
		while (format[*i] == '0')
			*i = *i + 1;
		g_flags->zero = 1;
	}
	while (format[*i] == '0' || format[*i] == '-')
		*i = *i + 1;
	if (g_flags->minus == 1)
		g_flags->zero = 0;
}
