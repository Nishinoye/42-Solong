/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:20:30 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 11:34:57 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compare s1 avec s2 jusqu'a size

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < size && (p1[i] || p2[i]))
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
