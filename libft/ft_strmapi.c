/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:52:03 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 15:18:58 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Applique la fonction f a chaque caractere de s et  
//enregistre le resultat dans la nouvelle chaine res

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = ((char *) ft_calloc(ft_strlen(s) + 1, sizeof(char)));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
