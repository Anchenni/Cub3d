/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:41:14 by anchenni          #+#    #+#             */
/*   Updated: 2020/10/13 21:54:11 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		++i;
		++str;
	}
	return (i);
}

void		*ft_memset(void *s, int c, size_t n)
{
	char *str;

	if (!s)
		return (0);
	str = s;
	while (n)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}

void		*ft_newstr(size_t size)
{
	void	*ptr;

	size++;
	ptr = malloc(size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

int			ft_lineread(void **str)
{
	if (*str)
	{
		ft_memset(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
