/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:27 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/23 10:47:04 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		while (*s && *s == c)
				++s;
		if (*s && *s != c)
		{
			++size;
			++s;
		}
		while (*s && *s != c)
			++s;
	}
	return (size + 1);
}

static int	ft_advance(char const *s, char c)
{
	int	j;

	j = 0;
	while (*(s + j) && *(s + j) != c)
		++j;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;
	int		j;

	size = ft_size(s, c);
	split = malloc(sizeof(char *) * size);
	if (!split)
		return (split);
	i = 0;
	while (i < size - 1)
	{
		while (*s == c)
			++s;
		j = ft_advance(s, c);
		*(split + i) = ft_substr(s, 0, j);
		if (!*(split + i))
			return ((char **) ft_memfree((void **) split, i));
		s += j;
		++i;
	}
	*(split + i) = NULL;
	return (split);
}
