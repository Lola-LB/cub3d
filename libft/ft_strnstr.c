/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:07:07 by lle-bret          #+#    #+#             */
/*   Updated: 2022/11/07 15:17:39 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && !len)
		return (0);
	if (!*to_find)
		return ((char *) str);
	while (*(str + i) && i < len)
	{
		if (*(str + i) == *(to_find + j))
		{
			++j;
			++i;
			if (!*(to_find + j))
				return ((char *) str + i - j);
		}
		else
		{
			i += (j == 0) - (j != 0) * (j - 1);
			j = 0;
		}
	}
	return (NULL);
}
