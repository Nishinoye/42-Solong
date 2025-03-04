/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:24:50 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 15:28:56 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Un write mais avec fd comme descripteur de fichier

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
