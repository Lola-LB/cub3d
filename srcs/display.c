/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/27 14:09:58 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	*get_img(t_data *data, int i, int j)
// {
// 	int	offset;

// 	if (data->map.content[i][j] == '1')
// 		return (data->texture[3].img);
// 	else if (data->map.content[i][j] == 'P')
// 	{
// 		offset = 4;
// 		if (data->left)
// 			offset = 8;
// 		return (data->texture[offset + data->move % 4].img);
// 	}
// 	else if (data->map.content[i][j] == 'C')
// 		return (data->texture[0].img);
// 	else if (data->map.content[i][j] == 'E' && data->coll == 0)
// 		return (data->texture[2].img);
// 	else if (data->map.content[i][j] == 'X')
// 		return (data->texture[13].img);
// 	return (NULL);
// }

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *) pixel = color;
}

void	display_background(t_data *data)
{
	int		i;
	int		j;

	if (!data->bg.img)
	{
		data->bg.img = mlx_new_image(&data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
		data->bg.addr = mlx_get_data_addr(data->bg.img, &data->bg.bpp,
			&data->bg.line_length, &data->bg.endian);
		i = 0;
		while (i < WINDOW_HEIGHT)
		{
			j = 0;
			while (j < WINDOW_WIDTH)
			{
				img_pixel_put(&data->bg, j, i,
					data->ceiling_color * (i < WINDOW_HEIGHT / 2)
					+ data->floor_color * (i >= WINDOW_HEIGHT / 2));
				++j;
			}
			++i;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->bg.img, 0, 0);
}

void	raycaster(t_data *data)
{
	t_raycaster	rc;
	double		time;
	double		oldTime;
	int			x;

	//x and y start position
	rc.pos = set_vect(22, 12);
	rc.dir = set_vect(-1, 0);
	rc.plane = set_vect(0, 0.66);

	time = 0; //time of current frame
	oldTime = 0; //time of previous frame

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		//calculate ray position and direction
		rc.cameraX = 2 * x / (double) WINDOW_WIDTH - 1; //x-coordinate in camera space
		rc.rayDir = vect_sum(rc.dir, scalar_mult(rc.plane, rc.cameraX));

		//which box of the map we're in
		rc.map.x = (int) rc.pos.x;
		rc.map.y = (int) rc.pos.y;

		//length of ray from one x or y-side to next x or y-side
		rc.deltaDist = set_vect(ft_doubleAbs(1 / rc.rayDir.x), ft_doubleAbs(1 / rc.rayDir.y));

		//what direction to step in x or y-direction (either +1 or -1)

		rc.hit = 0; //was there a wall hit?
		
		//calculate step and initial sideDist
		rc.step = step(rc.rayDir);
		rc.sideDist.x = rc.step.x * (rc.map.x - rc.pos.x + (rc.step.x >= 0)) * rc.deltaDist.x;
		rc.sideDist.y = rc.step.y * (rc.map.y - rc.pos.y + (rc.step.y >= 0)) * rc.deltaDist.y;

		//perform DDA
		while (rc.hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (rc.sideDist.x < rc.sideDist.y)
			{
				rc.sideDist.x += rc.deltaDist.x;
				rc.map.x += rc.step.x;
				rc.side = 0;
			}
			else
			{
				rc.sideDist.y += rc.deltaDist.y;
				rc.map.y += rc.step.y;
				rc.side = 1;
			}
			//Check if ray has hit a wall
			if (data->map.content[rc.map.x][rc.map.y] == '1')
				rc.hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (rc.side == 0)
			rc.perpWallDist = (rc.sideDist.x - rc.deltaDist.x);
		else
			rc.perpWallDist = (rc.sideDist.y - rc.deltaDist.y);

		//Calculate height of line to draw on screen
		rc.lineHeight = (int) (WINDOW_HEIGHT / rc.perpWallDist);

		//Calculate lowest and highest pixel to fill in current stripe
		rc.drawStart = ft_max(0, -rc.lineHeight / 2 + WINDOW_HEIGHT / 2);
		rc.drawEnd = ft_min(WINDOW_HEIGHT - 1, rc.lineHeight / 2 + WINDOW_HEIGHT / 2);
		
		int color = 255 << 8;	
		//give x and y sides different brightness
		if (rc.side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(x, rc.drawStart, rc.drawEnd, color);
		++x;
    }
}

void	images_to_map(t_data *data)
{
	int		i;
	int		j;
	t_img	img;

	display_background(data);
	img.img = mlx_new_image(&data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			++j;
		}
		++i;
	}
}
