/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:07:13 by lle-bret          #+#    #+#             */
/*   Updated: 2022/11/07 16:05:19 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (*s1 && ft_strchr(set, (int) *s1))
		++s1;
	while (*(s1 + i + 1))
		++i;
	while (i > 0 && ft_strchr(set, (int) *(s1 + i)))
		--i;
	if (!*s1)
		res = malloc(sizeof(char));
	else
		res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (res);
	j = 0;
	while (j <= i && *s1)
	{
		*(res + j) = *(s1 + j);
		++j;
	}
	*(res + j) = 0;
	return (res);
}
