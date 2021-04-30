/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:50:20 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (n == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < n - 1 && src[i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
