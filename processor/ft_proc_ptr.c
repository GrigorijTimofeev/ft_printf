/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:33:46 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/10 16:33:47 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

char	*ft_prec(unsigned long val, t_flags *g_flags, int i)
{
	char	*str;
	char	*str_temp;
	int		length;

	length = ft_count_16(val);
	if (g_flags->precision > length)
		str = malloc(sizeof(char) * (g_flags->precision + 3));
	else
		str = malloc(sizeof(char) * (length + 3));
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	g_flags->precision -= length;
	while (g_flags->precision-- > 0)
		str[i++] = '0';
	str_temp = malloc(sizeof(char) * (length + 1));
	if (!str_temp)
	{
		free(str);
		return (NULL);
	}
	ft_get_str_x(val, str_temp, length);
	ft_strlcpy(&str[i], str_temp, length + 1);
	free(str_temp);
	return (str);
}

char	*ft_prec_null(t_flags *g_flags)
{
	int		i;
	int		length;
	char	*str;

	str = malloc(sizeof(char) * (g_flags->precision + 3));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	length = g_flags->precision;
	while (length--)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

char	*ft_width_zero(char *str_temp, t_flags *g_flags)
{
	char	*str;
	int		length;
	int		i;

	length = ft_strlen(str_temp);
	if (g_flags->width <= length)
		return (str_temp);
	str = malloc(sizeof(char) * (g_flags->width + 1));
	if (!str)
	{
		free(str_temp);
		return (NULL);
	}
	str[0] = '0';
	str[1] = 'x';
	length = g_flags->width - length;
	i = 2;
	while (length--)
		str[i++] = '0';
	length = ft_strlen(str_temp) - 2;
	ft_strlcpy(&str[i], &str_temp[2], length + 1);
	str[g_flags->width] = '\0';
	free(str_temp);
	return (str);
}

int		ft_proc_ptr(t_flags *g_flags, va_list argptr)
{
	int				length;
	char			*str;
	unsigned long	val;

	str = NULL;
	val = va_arg(argptr, unsigned long);
	if (g_flags->precision >= 0 && val == 0)
		str = ft_prec_null(g_flags);
	else
		str = ft_prec(val, g_flags, 0);
	if (!str)
		return (-1);
	if (g_flags->width > 0 && g_flags->zero == 0)
		str = ft_width(str, g_flags);
	else if (g_flags->width > 0 && g_flags->zero == 1)
		str = ft_width_zero(str, g_flags);
	if (!str)
		return (-1);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
