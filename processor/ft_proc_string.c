/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:51:17 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 14:51:18 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_str_minus(int length, int width, char *str)
{
	int		temp;
	int		i;

	temp = width;
	width -= length;
	i = 0;
	while (length--)
		ft_putchar_fd(str[i++], 1);
	while (width--)
		ft_putchar_fd(' ', 1);
	return (temp);
}

int		ft_str_no_minus(int length, int width, char *str)
{
	int		temp;
	int		i;

	temp = width;
	width -= length;
	i = 0;
	while (width--)
		ft_putchar_fd(' ', 1);
	while (length--)
		ft_putchar_fd(str[i++], 1);
	return (temp);
}

char	*ft_allocate_null(const char *str_temp)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * 7);
	i = 0;
	j = 0;
	while (str_temp[i])
	{
		str[i] = str_temp[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_proc_string(t_flags *g_flags, va_list argptr)
{
	int		length;
	int		i;
	char	*str;

	str = va_arg(argptr, char*);
	if (str == NULL)
		str = ft_allocate_null("(null)");
	if (!str)
		return (-1);
	length = ft_strlen(str);
	if (g_flags->precision > length)
		g_flags->precision = -1;
	if (g_flags->precision >= 0)
		length = g_flags->precision;
	i = 0;
	if (g_flags->width > length && g_flags->minus == 1)
		length = ft_str_minus(length, g_flags->width, str);
	else if (g_flags->width > length && g_flags->minus == 0)
		length = ft_str_no_minus(length, g_flags->width, str);
	else if (g_flags->width <= length)
		while (i < length)
			ft_putchar_fd(str[i++], 1);
	return (length);
}
