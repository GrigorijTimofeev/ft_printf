/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:29:20 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 10:29:22 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		g_i;

char	*ft_add_precision_2(char *str, t_flags *g_flags,
			char *ret, int minus)
{
	int		j;

	if (!ret)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	if (minus == 1)
		ret[j++] = '-';
	while (g_flags->precision-- > 0)
		ret[j++] = '0';
	while (str[g_i])
		ret[j++] = str[g_i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*ft_add_precision(char *str, t_flags *g_flags, int length)
{
	int		minus;
	char	*ret;

	g_i = 0;
	minus = 0;
	if (str[g_i] == '-')
	{
		minus = 1;
		length--;
		g_i++;
	}
	g_flags->precision -= length;
	if (g_flags->precision > 0)
		length += g_flags->precision;
	length += minus;
	ret = malloc(sizeof(char) * (length + 1));
	return (ft_add_precision_2(str, g_flags, ret, minus));
}

char	*ft_add_width_2(char *str, t_flags *g_flags, int length, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_flags->width -= length;
	if (g_flags->minus == 1)
	{
		while (length--)
			ret[i++] = str[j++];
		while (g_flags->width--)
			ret[i++] = ' ';
	}
	if (g_flags->minus == 0)
	{
		while (g_flags->width--)
			ret[i++] = ' ';
		while (length--)
			ret[i++] = str[j++];
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	*ft_add_width(char *str, t_flags *g_flags, int length)
{
	char	*ret;

	if (g_flags->zero == 1)
	{
		if (str[0] == '-')
			g_flags->width--;
		g_flags->precision = g_flags->width;
		return (ret = ft_add_precision(str, g_flags, ft_strlen(str)));
	}
	ret = malloc(sizeof(char) * (g_flags->width + 1));
	if (!ret)
		return (NULL);
	return (ft_add_width_2(str, g_flags, length, ret));
}

int		ft_proc_dec(t_flags *g_flags, va_list argptr)
{
	int		length;
	char	*str;

	str = ft_itoa(va_arg(argptr, int));
	str = ft_chcek_get_empty_string_and_free(str, g_flags->precision);
	if (!str)
		return (-1);
	if (g_flags->precision >= 0)
	{
		str = ft_add_precision(str, g_flags, ft_strlen(str));
		if (!str)
			return (-1);
	}
	if (g_flags->width > (int)ft_strlen(str))
	{
		str = ft_add_width(str, g_flags, ft_strlen(str));
		if (!str)
			return (-1);
	}
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}
