/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:38:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2024/11/10 15:44:40 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comme putnbr mais avec fd cpmme descripteur de fichier

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(45, fd);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		n = n % 10 + 48;
		ft_putchar_fd(n, fd);
	}
}
