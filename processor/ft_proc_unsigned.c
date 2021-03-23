/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:39:58 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/09 15:40:00 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

char	*ft_unsg_to_str_2(int length, char *first, char *sec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
	{
		free(first);
		free(sec);
		return (NULL);
	}
	ret[length] = '\0';
	length--;
	i = ft_strlen(first) - 1;
	while (i >= 0)
		ret[length--] = first[i--];
	i = ft_strlen(sec) - 1;
	if (sec[0] != '0')
		while (i >= 0)
			ret[length--] = sec[i--];
	free(first);
	free(sec);
	return (ret);
}

char	*ft_unsg_to_str(unsigned int val)
{
	char	*first;
	char	*sec;
	int		temp;
	int		length;

	temp = val % 1000000;
	first = ft_itoa(temp);
	if (!first)
		return (NULL);
	temp = val / 1000000;
	sec = ft_itoa(temp);
	if (!sec)
	{
		free(first);
		return (NULL);
	}
	length = ft_strlen(first);
	if (sec[0] != '0')
		length += ft_strlen(sec);
	return (ft_unsg_to_str_2(length, first, sec));
}

int		ft_proc_unsigned(t_flags *g_flags, va_list argptr)
{
	int		length;
	char	*str;

	str = ft_unsg_to_str(va_arg(argptr, unsigned int));
	str = ft_chcek_get_empty_string_and_free(str, g_flags->precision);
	if (!str)
		return (-1);
	length = ft_proc_dec_uns(g_flags, str);
	return (length);
}
