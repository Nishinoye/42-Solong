/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:04:40 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/26 15:42:04 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Duplique la chaine src dans une nouvelle chaine res AVEC LE \0

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;

	res = (char *) ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, src, ft_strlen(src));
	return (res);
}
