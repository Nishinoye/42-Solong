/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:52:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/15 17:17:23 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Vide entierement une chaine de noeuds

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	while (*lst)
	{
		n = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = n;
	}
	*lst = NULL;
}
