/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:17:19 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_cpy;

	len = ft_strlen(s) + 1;
	if (!(s_cpy = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(s_cpy, s, len);
	return (s_cpy);
}
