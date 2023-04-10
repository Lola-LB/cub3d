/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:05:32 by lle-bret          #+#    #+#             */
/*   Updated: 2022/10/06 14:57:09 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_ptrsize(intptr_t n, intptr_t *pow, int base)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		++size;
		n *= -1;
	}
	while (n >= *pow)
	{
		*pow *= base;
		++size;
	}
	return (size);
}

char	*ft_ptrfill(char *str, intptr_t n, intptr_t pow, int base)
{
	int	i;
	int	neg;

	i = 0;
	neg = (n < 0);
	if (neg)
	{
		n *= -1;
		*(str + i++) = '-';
	}
	while (*(str + i))
	{
		pow /= base;
		if (n / pow < 10)
			*(str + i++) = '0' + n / pow;
		else
			*(str + i++) = 'a' + n / pow - 10;
		n = n % pow;
	}
	*(str + i) = 0;
	return (str);
}

char	*ft_itoa_ptr(intptr_t n, int base)
{
	char		*str;
	intptr_t	pow;
	int			size;

	pow = 1;
	size = (n == 0) + ft_get_ptrsize(n, &pow, base);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (str);
	str = ft_memset((void *) str, '0', size);
	*(str + size) = 0;
	return (ft_ptrfill(str, n, pow, base));
}
