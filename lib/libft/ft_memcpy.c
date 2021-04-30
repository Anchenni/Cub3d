/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:25:51 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tab1;
	unsigned char		*tab2;

	i = 0;
	if (!dest && !src)
		return (0);
	tab1 = (unsigned char*)dest;
	tab2 = (unsigned char*)src;
	if (tab1 == 0 && tab2 == 0)
		return (0);
	while (i < n)
	{
		tab1[i] = tab2[i];
		i++;
	}
	return (dest);
}
