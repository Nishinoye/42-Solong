/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:40:32 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 10:38:16 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Check si c est alphanumerique (aAzZ09)

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
