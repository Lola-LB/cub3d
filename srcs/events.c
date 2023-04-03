/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/03 13:50:11 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move(t_data *data, t_double_vect new_pos)
{
	int	x;
	int	y;

	x = (int) floor(new_pos.x);
	y = (int) floor(new_pos.y);
	if (x < 1 || y < 1 || x >= data->map->width || y >= data->map->len)
		return (0);
	if (data->map->content[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(int keysym, t_data *data)
{
	t_double_vect	new_pos;
	int				way;

	new_pos = data->rc->player;
	way = (keysym == W) + (keysym == D) - (keysym == S) - (keysym == A);
	if (keysym == W || keysym == S)
		new_pos = vect_sum(new_pos, scalar_mult(data->rc->dir,
					data->move_speed * way));
	else if (keysym == A || keysym == D)
		new_pos = vect_sum(new_pos, scalar_mult(data->rc->plane,
					data->move_speed * way));
	if (check_move(data, new_pos))
	{
		data->rc->player = new_pos;
		raycaster(data, data->screen, 0, WINDOW_WIDTH);
	}
}

void	shift_screen(t_data *data, int left)
{
	if (left)
	{
		ft_memmove((int *) data->screen->addr + (int)data->rotate_speed,
			(int *) data->screen->addr, data->screen->line_length
			* data->screen->height - (int) data->rotate_speed);
	}
	else
	{
		ft_memmove((int *) data->screen->addr, (int *) data->screen->addr
			+ (int) data->rotate_speed, data->screen->line_length
			* data->screen->height - (int) data->rotate_speed);
	}
}

void	rotate_view(int keysym, t_data *data)
{
	data->rc->dir = rotate_vect(data, data->rc->dir, (keysym == LEFT));
	data->rc->plane = rotate_vect(data, data->rc->plane, (keysym == LEFT));
	shift_screen(data, keysym == LEFT);
	if (keysym == LEFT)
		raycaster(data, data->screen, 0, data->rotate_speed);
	else if (keysym == RIGHT)
		raycaster(data, data->screen, WINDOW_WIDTH - data->rotate_speed,
			WINDOW_WIDTH);
	raycaster(data, data->screen, 0, WINDOW_WIDTH);
}

/*printf("%i\n", keysym);*/
int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_game(data);
	else if (keysym == W || keysym == A || keysym == S || keysym == D)
		move_player(keysym, data);
	else if (keysym == DEBUG)
		print_rc(data);
	else if (keysym == LEFT || keysym == RIGHT)
		rotate_view(keysym, data);
	return (0);
}
