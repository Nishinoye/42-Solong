/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:32:34 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/15 17:24:58 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Rajoute un \n a la suite de la chaine de caractere 
//avec fd comme descripteur de fichier

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd(10, fd);
}
