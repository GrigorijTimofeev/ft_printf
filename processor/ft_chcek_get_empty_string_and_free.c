/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chcek_get_empty_string_and_free.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:21:34 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/11 15:21:35 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

char	*ft_chcek_get_empty_string_and_free(char *str, int precision)
{
	if (!str)
		return (NULL);
	if (str[0] == '0' && precision != -1)
	{
		free(str);
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
