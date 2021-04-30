/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:48:50 by anchenni          #+#    #+#             */
/*   Updated: 2020/07/16 20:03:32 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t str, size_t n)
{
	void *tab;

	if (!(tab = malloc(str * n)))
		return (0);
	ft_bzero(tab, (str * n));
	return (tab);
}
