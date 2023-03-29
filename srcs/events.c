/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 18:46:59 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(int keysym, t_data *data)
{
	if (keysym == W && data->player.y - data->moveSpeed > 1
		&& (floor(data->player.y - data->moveSpeed) == data->rc->square.y
		|| data->map->content[data->rc->square.x][data->rc->square.y - 1] != '1'))
	{
		data->player.y -= data->moveSpeed;
	}
	else if (keysym == S && data->player.y + data->moveSpeed < data->map->len - 1
		&& (floor(data->player.y + data->moveSpeed) == data->rc->square.y
		|| data->map->content[data->rc->square.x][data->rc->square.y + 1] != '1'))
	{
		data->player.y += data->moveSpeed;
	}
	else if (keysym == A && data->player.x - data->moveSpeed > 1
		&& (floor(data->player.x - data->moveSpeed) == data->rc->square.x
		|| data->map->content[data->rc->square.x - 1][data->rc->square.y] != '1'))
	{
		data->player.x -= data->moveSpeed;
	}
	else if (keysym == D && data->player.x + data->moveSpeed < data->map->width - 1
		&& (floor(data->player.x + data->moveSpeed) == data->rc->square.x
		|| data->map->content[data->rc->square.x + 1][data->rc->square.y] != '1'))
	{
		data->player.x += data->moveSpeed;
	}
	raycaster(data);
}

int	handle_key(int keysym, t_data *data)
{
	printf("%i\n", keysym);
	if (keysym == XK_Escape)
		end_game(data);
	else if (!data->end_game && (keysym == W || keysym == A || keysym == S
			|| keysym == D))
		move_player(keysym, data);
	// else if (keysym == LEFT || keysym == RIGHT)
	// 	rotate_view(keysym, data);
	return (0);
}
