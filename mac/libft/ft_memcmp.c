/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:10:39 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/26 15:00:42 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*((unsigned char *) s1) == *((unsigned char *) s2) && n - 1 > 0)
	{
		++s1;
		++s2;
		--n;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
