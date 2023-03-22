/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:12:48 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/07 18:02:29 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	expand_path(char **map, int px, int py)
{
	if (map[px][py] != '1' && map[px][py] != 'P')
	{
		map[px][py] = 'P';
		explore_map(map, px, py);
	}
	return ;
}

void	explore_map(char **map, int px, int py)
{
	if (px)
		expand_path(map, px - 1, py);
	if (py)
		expand_path(map, px, py - 1);
	if (map[px][py + 1])
		expand_path(map, px, py + 1);
	if (map[px + 1])
		expand_path(map, px + 1, py);
	return ;
}

int	check_final(t_map map, int px)
{
	int	py;

	while (map.map[px + 1])
	{
		py = 1;
		while (map.map[px][py + 1])
		{
			if (map.map[px][py] == 'C' || map.map[px][py] == 'E')
			{
				free_map(map);
				return (0);
			}
			++py;
		}
		++px;
	}
	free_map(map);
	return (1);
}

void	valid_path(t_map map)
{
	t_map	map_copy;
	int		px;
	int		py;

	map_copy.map = ft_mapcopy(map);
	map_copy.len = map.len;
	if (!map_copy.map)
	{
		free_map(map);
		ft_error(NULL, MALLOC_ERROR);
	}
	px = 0;
	py = 1;
	while (map_copy.map[px + 1] && map_copy.map[px][py] != 'P')
	{
		++px;
		py = 1;
		while (map_copy.map[px][py] && map_copy.map[px][py] != 'P')
			++py;
	}
	explore_map(map_copy.map, px, py);
	if (!check_final(map_copy, 1))
	{
		free_map(map);
		ft_error(NULL, NO_VALID_PATH);
	}
}

char	**ft_mapcopy(t_map src)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char *) * (src.len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < src.len)
	{
		dest[i] = malloc(sizeof(char) * (src.width + 1));
		if (!dest[i])
		{
			while (--i)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		dest[i] = ft_strcpy(dest[i], src.map[i]);
		++i;
	}
	dest[i] = NULL;
	return (dest);
}
