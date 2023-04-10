/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:05:32 by lle-bret          #+#    #+#             */
/*   Updated: 2022/11/07 16:51:49 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(long int n)
{
	int	size;

	size = 1 + (n < 0);
	while (n / 10 != 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

static char	*ft_fill(char *str, long int n, int size)
{
	int	i;
	int	neg;

	i = 0;
	neg = (n < 0);
	if (neg)
		*(str + i) = '-';
	while (i < size - neg)
	{
		*(str + size - i++ - 1) = '0' + ((n > 0) * n - (n < 0) * n) % 10;
		n = n / 10;
	}
	*(str + size) = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;

	size = ft_get_size(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (str);
	return (ft_fill(str, (long) n, size));
}
