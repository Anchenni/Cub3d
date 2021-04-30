/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:35:10 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t l;
	size_t b;

	if (!ft_strlen(needle) || !haystack)
		return ((char *)haystack);
	b = 0;
	while (haystack[b] && b < len)
	{
		l = 0;
		while (needle[l] && haystack[b + l] && needle[l] == haystack[b + l]
			&& (b + l) < len)
			l++;
		if (!needle[l])
			return ((char*)&haystack[b]);
		b++;
	}
	return (0);
}
