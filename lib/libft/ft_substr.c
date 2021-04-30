/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:51:37 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	r;

	r = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (len + start > ft_strlen(s) && start < ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (r < len)
	{
		res[r] = s[start];
		r++;
		start++;
	}
	res[r] = '\0';
	return (res);
}
