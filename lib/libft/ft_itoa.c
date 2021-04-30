/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:41:28 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int nbr)
{
	long	n;
	size_t	len;
	char	*tab;

	n = nbr;
	len = (n > 0) ? 0 : 1;
	n = (n > 0) ? n : -n;
	while (nbr)
		nbr = len++ ? nbr / 10 : nbr / 10;
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	*(tab + len--) = '\0';
	while (n > 0)
	{
		*(tab + len--) = n % 10 + '0';
		n /= 10;
	}
	if (len == 0 && tab[1] == '\0')
		*(tab + len) = '0';
	if (len == 0 && tab[1] != '\0')
		*(tab + len) = '-';
	return (tab);
}
