/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:16:21 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 15:26:08 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Applique la fonction f a chaque caractere de s en utilisant l'adresse de s[i]

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
