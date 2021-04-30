/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:02:37 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy(char *dest, char const *src, char c)
{
	int i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		make_word(char const *s, char c)
{
	int	a;
	int i;

	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			a++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (a);
}

static char		*fill_word(char const *s, char c)
{
	char	*a;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(a = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	ft_strcpy(a, s, c);
	return (a);
}

static char		**free_tab(char **tab, int i)
{
	while (i)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (make_word(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			if (!(tab[i] = fill_word(&s[j], c)))
				return (free_tab(tab, i));
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
