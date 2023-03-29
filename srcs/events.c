/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 16:55:58 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	swap_player(t_data *data, t_int_vect old, int x, int y)
// {
// 	data->burp = 0;
// 	if (data->map->content[x][y] != '1')
// 	{
// 		if (data->map->content[x][y] == 'E' && data->coll == 0)
// 			end_screen(data, 1);
// 		else
// 		{
// 			if (data->map->content[x][y] == 'C')
// 			{
// 				data->coll--;
// 				data->burp = 1;
// 				if (!data->coll)
// 					data->map->content[data->exit.x][data->exit.y] = 'E';
// 			}
// 			data->map->content[x][y] = 'P';
// 			data->map->content[old.x][old.y] = '0';
// 			data->player.x = x;
// 			data->player.y = y;
// 			data->move++;
// 		}
// 	}
// }

// void	move_player(int keysym, t_data *data)
// {
// 	if (keysym == W && data->player.x)
// 		swap_player(data, data->player, data->player.x - 1, data->player.y);
// 	else if (keysym == A && data->player.y)
// 	{
// 		if (data->left)
// 			swap_player(data, data->player,
// 				data->player.x, data->player.y - 1);
// 		else
// 			data->left = 1;
// 	}
// 	else if (keysym == S && data->player.x != data->map->len)
// 		swap_player(data, data->player, data->player.x + 1, data->player.y);
// 	else if (keysym == D && data->player.y != data->map->width)
// 	{
// 		if (data->left)
// 			data->left = 0;
// 		else
// 			swap_player(data, data->player,
// 				data->player.x, data->player.y + 1);
// 	}
// }

int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_game(data);
	// else if (!data->end_game && (keysym == W || keysym == A || keysym == S
	// 		|| keysym == D))
	// {
	// 	move_player(keysym, data);
	// 	if (!data->end_game)
	// 		images_to_map(data);
	// }
	return (0);
}
