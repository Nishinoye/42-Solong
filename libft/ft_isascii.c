/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:56:06 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 09:57:42 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Check si c est dans la table ascii

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
