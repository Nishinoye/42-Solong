/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:02:49 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 02:17:30 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_bzero(void *str, size_t count)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) str;
	i = 0;
	while (i < count)
	{
		ptr[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *src)
{
	char	*res;

	res = (char *) ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, src, ft_strlen(src));
	return (res);
}

void	*ft_calloc(size_t count, size_t type)
{
	void		*ptr;

	ptr = malloc(type * count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, type * count);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
