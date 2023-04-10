/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:06:53 by lle-bret          #+#    #+#             */
/*   Updated: 2022/10/06 14:56:44 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(res + i) = (*f)(*(s + i));
		++i;
	}
	return (res);
}
