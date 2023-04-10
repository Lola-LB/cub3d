/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:05:12 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/22 19:56:24 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buff;

	buff = malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (size * nmemb));
	return (buff);
}
