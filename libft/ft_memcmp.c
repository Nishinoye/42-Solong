/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:58:23 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 10:27:47 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compare les octets pt1 et pt2 jusqu'a size

#include "libft.h"

int	ft_memcmp(const void *pt1, const void *pt2, size_t size)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)pt1;
	s2 = (unsigned char *)pt2;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
		i++;
	}
	return (0);
}
