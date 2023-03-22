/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:47 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/26 16:20:15 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (ft_strlen((char *) src));
	i = (size_t) ft_strlen(dst);
	if (i > size)
		return (size + (size_t) ft_strlen((char *) src));
	j = 0;
	while (i + j + 1 < size && *(src + j))
	{
		*(dst + i + j) = *(src + j);
		++j;
	}
	if (size > 0)
		*(dst + i + j) = 0;
	return (i + (size_t) ft_strlen((char *) src));
}
