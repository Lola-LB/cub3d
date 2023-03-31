/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/31 14:00:13 by lle-bret         ###   ########.fr       */
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

	newPos = data->rc->player;
	
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
		data->rc->player = newPos;
		raycaster(data, data->screen, 0, WINDOW_WIDTH);
	}
}

void	shift_screen(t_data *data, int left)
{
	if (left)
	{
		ft_memmove((int*)data->screen->addr + (int)data->rotateSpeed,
			(int*)data->screen->addr, data->screen->line_length
			* data->screen->height - (int)data->rotateSpeed);
	}
	else
	{
		ft_memmove((int*)data->screen->addr, (int*)data->screen->addr
			+ (int)data->rotateSpeed, data->screen->line_length
			* data->screen->height - (int)data->rotateSpeed);
	}
}

void	rotate_view(int keysym, t_data *data)
{
	data->rc->dir = rotate_vect(data, data->rc->dir, (keysym == LEFT));
	data->rc->plane = rotate_vect(data, data->rc->plane, (keysym == LEFT));
	shift_screen(data, keysym == LEFT);
	if (keysym == LEFT)
		raycaster(data, data->screen, 0, data->rotateSpeed);
	else if (keysym == RIGHT)
		raycaster(data, data->screen, WINDOW_WIDTH - data->rotateSpeed,
			WINDOW_WIDTH);
	raycaster(data, data->screen, 0, WINDOW_WIDTH);
}

int	handle_key(int keysym, t_data *data)
{
	// printf("%i\n", keysym);
	if (keysym == XK_Escape)
		end_game(data);
	else if (keysym == W || keysym == A || keysym == S || keysym == D)
		move_player(keysym, data);
	else if (keysym == DEBUG) //Space on mac
		print_rc(data);
	else if (keysym == LEFT || keysym == RIGHT)
		rotate_view(keysym, data);
	return (0);
}
