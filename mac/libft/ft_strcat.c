/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:28 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:06:30 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (*(dst + i))
		++i;
	j = 0;
	while (*(src + j))
	{
		*(dst + i) = *(src + j);
		++i;
		++j;
	}
	*(dst + i) = 0;
	return (dst);
}
