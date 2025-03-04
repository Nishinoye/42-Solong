/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:57:24 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/25 18:21:50 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cree une nouvelle chaine res et concatene s1 et s2 dedans AVEC LE \0

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = ft_calloc(i + j + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, i);
	ft_strlcat(res, s2, i + j + 1);
	return (res);
}
