/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:24:36 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/01 15:06:53 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *source, size_t old_size, size_t new_size)
{
	void	*dest;

	dest = malloc(new_size);
	dest = ft_memcpy(dest, source, ft_min(old_size, new_size));
	ft_bzero(dest + ft_min(old_size, new_size), ft_abs(new_size - old_size));
	free(source);
	return (dest);
}
