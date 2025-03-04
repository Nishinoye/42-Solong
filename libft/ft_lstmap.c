/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:48:57 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/21 17:21:39 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Applique la fonction f a tout les noeuds de la liste lst et 
//retourne le resultat dans une nouvelle chaine

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*swap;
	t_list	*res;
	void	*content;

	if (!lst)
		return (NULL);
	swap = lst;
	res = NULL;
	while (swap)
	{
		content = f(swap->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&res, del);
		}
		ft_lstadd_back(&res, new);
		swap = swap->next;
	}
	ft_lstclear(&swap, del);
	return (res);
}
