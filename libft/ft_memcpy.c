/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:28 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 11:00:58 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copie les octets de src dans des jusqu'a size

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (size == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	while (i < size)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dest);
}
