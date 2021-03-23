/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:34:39 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/07 15:34:41 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		length;
	int		temp;
	int		i;
	va_list	argptr;

	va_start(argptr, format);
	length = 0;
	i = 0;
	while (format[i])
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			length++;
			i++;
		}
		else if ((temp = ft_parser(argptr, format, &i)) >= 0)
			length += temp;
		else
		{
			va_end(argptr);
			return (-1);
		}
	va_end(argptr);
	return (length);
}
