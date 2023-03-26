/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:37:17 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 13:38:58 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_free(void **ar, int size)
{
	if (ar)
	{
		while (size)
		{
			if (ar[size - 1])
				free(ar[size - 1]);
			--size;
		}
		free(ar);
	}
}