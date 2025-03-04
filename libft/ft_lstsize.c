/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:55:47 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/15 17:23:11 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Retourne le nombre de noeud dans la liste lst

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		size;

	ptr = lst;
	size = 0;
	if (lst == NULL)
		return (0);
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
