/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:13 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 09:55:37 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mettre tout les octets a 0 jusqu'a la taille count

#include "libft.h"

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
