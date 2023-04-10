/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:55 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/26 16:47:55 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen((char *) s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (res);
	i = 0;
	while (i < len)
	{
		*(res + i) = (*f)(i, *(s + i));
		++i;
	}
	*(res + i) = 0;
	return (res);
}
