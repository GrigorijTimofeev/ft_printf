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

char	*ft_add_precision_u(char *str, t_flags *g_flags, int length)
{
	char	*ret;
	int		j;
	int		i;

	i = 0;
	g_flags->precision -= length;
	if (g_flags->precision > 0)
		length += g_flags->precision;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (g_flags->precision-- > 0)
		ret[j++] = '0';
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*ft_add_width_2_u(char *str, t_flags *g_flags, int length, char *ret)
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

char	*ft_add_width_u(char *str, t_flags *g_flags, int length)
{
	char	*ret;

	if (g_flags->zero == 1)
	{
		g_flags->precision = g_flags->width;
		return (ret = ft_add_precision_u(str, g_flags, ft_strlen(str)));
	}
	ret = malloc(sizeof(char) * (g_flags->width + 1));
	if (!ret)
		return (NULL);
	return (ft_add_width_2_u(str, g_flags, length, ret));
}

int		ft_proc_dec_uns(t_flags *g_flags, char *str)
{
	int		length;

	if (g_flags->precision >= 0)
	{
		str = ft_add_precision_u(str, g_flags, ft_strlen(str));
		if (!str)
			return (-1);
	}
	if (g_flags->width > (int)ft_strlen(str))
	{
		str = ft_add_width_u(str, g_flags, ft_strlen(str));
		if (!str)
			return (-1);
	}
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}
