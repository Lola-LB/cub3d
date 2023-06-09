/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:02:55 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/01 15:04:33 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoins(char *s1, char *s2, size_t len)
{
	size_t	i;
	char	*buff;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	buff = malloc(sizeof(char) * (i + len + 1));
	if (!buff)
		return (NULL);
	ft_memcpy(buff, s1, i);
	ft_memcpy(buff + i, s2, (len + 1));
	free(s1);
	return (buff);
}
