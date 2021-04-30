/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:37:02 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		l;
	unsigned int		j;
	size_t				cont;

	i = 0;
	l = 0;
	j = 0;
	cont = ft_strlen(src);
	if (size)
	{
		while (src[l])
			l++;
		while (dst[i])
			i++;
		if (size <= i)
			l = l + size;
		else
			l = l + i;
		while (i + 1 < size && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (l);
	}
	return (cont);
}
