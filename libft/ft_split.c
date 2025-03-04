/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:17:31 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 10:51:28 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Coupe la chaine de caractere s en la splitant 
//dans un nouveau tableau de chaine res

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	lenword(char const *s, char c, size_t index)
{
	size_t	i;

	i = 0;
	while (s[index + i] && s[index + i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **res)
{
	size_t	x;

	x = 0;
	while (res[x])
	{
		free(res[x]);
		x++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	x;
	char	**res;

	i = 0;
	x = 0;
	res = (char **) malloc((sizeof(char *) * (countwords(s, c) + 1)));
	if (res == NULL)
		return (NULL);
	while (s[i] && i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			res[x] = ft_substr(s, i, lenword(s, c, i));
		else
			break ;
		if (res[x] == NULL)
			return (ft_free(res));
		x++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
	}
	res[x] = NULL;
	return (res);
}
