/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/06 19:12:29 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**file_names(void)
{
	static char	*files[NB_FILES] = {"files/beer.xpm", "files/grass.xpm",
		"files/lad.xpm", "files/bush.xpm", "files/char_1.xpm",
		"files/char_2.xpm", "files/char_3.xpm", "files/char_4.xpm",
		"files/char_1_left.xpm", "files/char_2_left.xpm",
		"files/char_3_left.xpm", "files/char_4_left.xpm",
		"files/burp.xpm", "files/police.xpm", "files/game_over.xpm",
		"files/win_screen.xpm", "files/numbers_0.xpm", "files/numbers_1.xpm",
		"files/numbers_2.xpm", "files/numbers_3.xpm", "files/numbers_4.xpm",
		"files/numbers_5.xpm", "files/numbers_6.xpm", "files/numbers_7.xpm",
		"files/numbers_8.xpm", "files/numbers_9.xpm", "files/gameboy.xpm"};

	return ((char **) files);
}

void	init_images(t_param *param)
{
	t_img	*images;
	char	**files;
	int		i;

	files = file_names();
	images = (t_img *) ft_calloc(sizeof(t_img), NB_FILES);
	param->img = images;
	if (!images)
		ft_error(param, MALLOC_ERROR);
	i = 0;
	while (i < NB_FILES)
	{
		images[i].img = mlx_xpm_file_to_image(param->mlx, files[i],
				&images[i].width, &images[i].height);
		if (!images[i].img)
			ft_error(param, FILE_ERROR);
		++i;
	}
}

void	*get_img(t_param *param, int i, int j)
{
	int	offset;

	if (param->map.map[i][j] == '1')
		return (param->img[3].img);
	else if (param->map.map[i][j] == 'P')
	{
		offset = 4;
		if (param->left)
			offset = 8;
		return (param->img[offset + param->move % 4].img);
	}
	else if (param->map.map[i][j] == 'C')
		return (param->img[0].img);
	else if (param->map.map[i][j] == 'E' && param->coll == 0)
		return (param->img[2].img);
	else if (param->map.map[i][j] == 'X')
		return (param->img[13].img);
	return (NULL);
}

void	burp(t_param *param)
{
	if (param->burp)
	{
		mlx_put_image_to_window(param->mlx, param->win, param->img[12].img,
			(param->player.y + 0.5) * NB_PIXEL, param->player.x * NB_PIXEL);
	}
}

void	images_to_map(t_param *param)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	mlx_put_image_to_window(param->mlx, param->win, param->img[1].img, 0, 0);
	while (i < param->map.len)
	{
		j = 0;
		while (j < param->map.width)
		{
			img = get_img(param, i, j);
			if (img)
				mlx_put_image_to_window(param->mlx,
					param->win, img, j * NB_PIXEL, i * NB_PIXEL);
			++j;
		}
		++i;
	}
	burp(param);
	display_score(param);
}
