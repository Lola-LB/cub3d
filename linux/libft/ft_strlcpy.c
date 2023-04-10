/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:49 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:36:48 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && *(src + i))
	{
		*(dst + i) = *(src + i);
		++i;
	}
	if (size > 0)
		*(dst + i) = 0;
	return ((size_t) ft_strlen((char *) src));
}
