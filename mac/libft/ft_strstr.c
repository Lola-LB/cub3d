/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:07:10 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:07:12 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (*(str + i) == *(to_find + j))
			++j;
		if (!*(to_find + j))
			return ((char *) str + i - j);
		++i;
	}
	return (NULL);
}
