/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_to_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:14:44 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/10 12:14:45 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

char	ft_get_table_x(int mod)
{
	if (mod >= 10)
	{
		if (mod == 10)
			return ('a');
		else if (mod == 11)
			return ('b');
		else if (mod == 12)
			return ('c');
		else if (mod == 13)
			return ('d');
		else if (mod == 14)
			return ('e');
		else if (mod == 15)
			return ('f');
	}
	return (mod + 48);
}

char	ft_get_table_x_big(int mod)
{
	if (mod >= 10)
	{
		if (mod == 10)
			return ('A');
		else if (mod == 11)
			return ('B');
		else if (mod == 12)
			return ('C');
		else if (mod == 13)
			return ('D');
		else if (mod == 14)
			return ('E');
		else if (mod == 15)
			return ('F');
	}
	return (mod + 48);
}

int		ft_count_16(unsigned long val)
{
	int		count;

	count = 0;
	while (val >= 16)
	{
		val /= 16;
		count++;
	}
	count++;
	return (count);
}

void	ft_get_str_x_big(unsigned long val, char *str, int length)
{
	int		mod;

	mod = val % 16;
	if (val >= 16)
		ft_get_str_x_big(val / 16, str, length - 1);
	else
	{
		str[length - 1] = ft_get_table_x_big(val);
		return ;
	}
	str[length - 1] = ft_get_table_x_big(mod);
}

void	ft_get_str_x(unsigned long val, char *str, int length)
{
	int		mod;

	mod = val % 16;
	if (val >= 16)
		ft_get_str_x(val / 16, str, length - 1);
	else
	{
		str[length - 1] = ft_get_table_x(val);
		return ;
	}
	str[length - 1] = ft_get_table_x(mod);
}
