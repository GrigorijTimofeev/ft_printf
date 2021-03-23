/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_ptr_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:10:27 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/11 11:10:28 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

char	*ft_width_2(char *str_temp, t_flags *g_flags,
			int length, char *str)
{
	int		i;

	g_flags->width -= length;
	if (g_flags->minus == 1)
	{
		i = length;
		ft_strlcpy(str, str_temp, length + 1);
		while (g_flags->width--)
			str[i++] = ' ';
		str[i] = '\0';
	}
	else
	{
		i = 0;
		while (g_flags->width--)
			str[i++] = ' ';
		ft_strlcpy(&str[i], str_temp, length + 1);
	}
	free(str_temp);
	return (str);
}

char	*ft_width(char *str_temp, t_flags *g_flags)
{
	char	*str;
	int		length;

	length = ft_strlen(str_temp);
	if (g_flags->width <= length)
		return (str_temp);
	str = malloc(sizeof(char) * (g_flags->width + 1));
	if (!str)
	{
		free(str_temp);
		return (NULL);
	}
	str[g_flags->width] = '\0';
	return (ft_width_2(str_temp, g_flags, length, str));
}
