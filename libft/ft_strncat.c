/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:57 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:06:58 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(dst + i))
		++i;
	j = 0;
	while (j < len && *(src + j))
	{
		*(dst + i) = *(src + j);
		++i;
		++j;
	}
	*(dst + i) = 0;
	return (dst);
}
