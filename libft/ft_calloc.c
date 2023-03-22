/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:05:12 by lle-bret          #+#    #+#             */
/*   Updated: 2022/11/07 16:06:16 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char				*buf;
	size_t				i;
	unsigned long long	test;

	test = ((unsigned long long) count) * ((unsigned long long) size);
	if (test > SIZE_MAX)
		return (NULL);
	buf = malloc(count * size);
	if (!buf)
		return (buf);
	i = 0;
	while (i < size * count)
		*(buf + i++) = 0;
	return (buf);
}
