/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 23:38:05 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move(t_data *data, t_double_vect newPos)
{
	int	x;
	int	y;

	x = (int) floor(newPos.x);
	y = (int) floor(newPos.y);
	if (x < 1 || y < 1 || x >= data->map->width || y >= data->map->len)
		return (0);
	if (data->map->content[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(int keysym, t_data *data)
{
	t_double_vect	newPos;

	newPos = data->player;
	
	if (keysym == W)
	{
		newPos.x += data->moveSpeed * data->rc->dir.x;
		newPos.y += data->moveSpeed * data->rc->dir.y;
	}
	else if (keysym == S)
	{
		newPos.x -= data->moveSpeed * data->rc->dir.x;
		newPos.y -= data->moveSpeed * data->rc->dir.y;
	}
	else if (keysym == A)
	{
		newPos.x -= data->moveSpeed * data->rc->plane.x;
		newPos.y -= data->moveSpeed * data->rc->plane.y;
	}
	else if (keysym == D)
	{
		newPos.x += data->moveSpeed * data->rc->plane.x;
		newPos.y += data->moveSpeed * data->rc->plane.y;
	}
	if (check_move(data, newPos))
	{
		data->player = newPos;
		raycaster(data);
	}
}

int	handle_key(int keysym, t_data *data)
{
	// printf("%i\n", keysym);
	if (keysym == XK_Escape)
		end_game(data);
	else if (!data->end_game && (keysym == W || keysym == A || keysym == S
			|| keysym == D))
		move_player(keysym, data);
	else if (keysym == DEBUG) //Space on mac
	{
		print_rc(data);
	}
	// else if (keysym == LEFT || keysym == RIGHT)
	// 	rotate_view(keysym, data); //TODO
	return (0);
}
