/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 18:31:01 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	*get_img(t_param *param, int i, int j)
// {
// 	int	offset;

// 	if (param->map.content[i][j] == '1')
// 		return (param->texture[3].img);
// 	else if (param->map.content[i][j] == 'P')
// 	{
// 		offset = 4;
// 		if (param->left)
// 			offset = 8;
// 		return (param->texture[offset + param->move % 4].img);
// 	}
// 	else if (param->map.content[i][j] == 'C')
// 		return (param->texture[0].img);
// 	else if (param->map.content[i][j] == 'E' && param->coll == 0)
// 		return (param->texture[2].img);
// 	else if (param->map.content[i][j] == 'X')
// 		return (param->texture[13].img);
// 	return (NULL);
// }

// void	burp(t_param *param)
// {
// 	if (param->burp)
// 	{
// 		mlx_put_image_to_window(param->mlx, param->win, param->texture[12].img,
// 			(param->player.y + 0.5) * NB_PIXEL, param->player.x * NB_PIXEL);
// 	}
// }

// void	images_to_map(t_param *param)
// {
// 	int		i;
// 	int		j;
// 	void	*img;

// 	i = 0;
// 	mlx_put_image_to_window(param->mlx, param->win, param->texture[1].img, 0, 0);
// 	while (i < param->map.len)
// 	{
// 		j = 0;
// 		while (j < param->map.width)
// 		{
// 			img = get_img(param, i, j);
// 			if (img)
// 				mlx_put_image_to_window(param->mlx,
// 					param->win, img, j * NB_PIXEL, i * NB_PIXEL);
// 			++j;
// 		}
// 		++i;
// 	}
// 	burp(param);
// 	display_score(param);
// }
