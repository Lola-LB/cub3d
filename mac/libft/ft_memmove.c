/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:13 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/26 15:43:18 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (dst < src && i < len)
	{
		*((char *) dst + i) = *((char *) src + i);
		++i;
	}
	i = len;
	while (dst >= src && i > 0)
	{
		*((char *) dst + i - 1) = *((char *) src + i - 1);
		--i;
	}
	return (dst);
}
