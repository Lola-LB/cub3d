/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:00 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:24:36 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) dst + i) = *((unsigned char *) src + i);
		if (*((unsigned char *) src + i) == (unsigned char) c)
			return (dst + ++i);
		++i;
	}
	return (NULL);
}
