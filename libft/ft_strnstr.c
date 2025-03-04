/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:56 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 11:43:33 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cherche ENTIEREMENT s2 dans s1 et renvoi 
//l'adresse de l'occurence de s2 dans s1

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < size)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < size && s2[j] && s1[i + j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
