/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:39:50 by anchenni          #+#    #+#             */
/*   Updated: 2020/10/13 21:27:15 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *str)
{
	char	*new;
	ssize_t	i;

	new = ft_newstr(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (s && c && s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

int		next_gext_next_line(int fd, char **line, ssize_t i, char *temp)
{
	char			buffer[BUFFER_SIZE + (i = 1)];
	static char		*myline = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	myline == NULL ? myline = ft_newstr(0) : NULL;
	while (!ft_strchr(myline, '\n') && (i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		temp = ft_strjoin(myline, buffer);
		ft_lineread((void **)&myline);
		myline = temp;
	}
	if (i < 0 || myline == NULL)
		return (-1);
	if (i == 0)
		*line = ft_strdup(myline);
	else if (i > 0)
		*line = ft_substr(myline, 0, (ft_strchr(myline, '\n') - myline));
	else
		return (-1);
	temp = ft_strdup(myline + (ft_strlen(*line) + ((i > 0) ? +1 : +0)));
	ft_lineread((void **)&myline);
	myline = temp;
	return (i == 0 ? 0 * ft_lineread((void **)&myline) : 1);
}

int		get_next_line(int fd, char **line)
{
	ssize_t	i;
	char	*temp;

	temp = NULL;
	i = 0;
	return (next_gext_next_line(fd, line, i, temp));
}
