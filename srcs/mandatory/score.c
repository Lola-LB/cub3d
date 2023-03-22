/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:32:08 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/17 18:44:30 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_score(t_param *param)
{
	int	score;
	int	number;
	int	i;

	score = param->move;
	ft_printf("%d\n", score);
	i = 0;
	while (score)
	{
		number = score % 10;
		score /= 10;
		mlx_put_image_to_window(param->mlx, param->win,
			param->img[NUM_OFFSET + number].img,
			param->map.width * NB_PIXEL - i * 37 - 37, 3);
		++i;
	}
}
