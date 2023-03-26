/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:13:32 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 18:00:51 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_lines(int fd, t_param *param)
{
	int		i;
	int		len;
	char	*line;

	len = MAP_LEN;
	param->map.content = (char **) ft_calloc(len, sizeof(char *));
	i = 0;
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (i == len)
		{
			param->map.content = (char **) ft_realloc(param->map.content, sizeof(char *) * len, sizeof(char *) * (len + MAP_LEN));
			len += MAP_LEN;
		}
		param->map.content[i] = line;
		line = get_next_line(fd);
		++i;
	}
	param->map.content = (char **) ft_realloc(param->map.content, sizeof(char *) * (i + 1), sizeof(char *) * len);
	param->map.content[i] = NULL;
}

void	rectangular_map(t_param *param)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (param->map.content[i])
	{
		len = ft_strlen(param->map.content[i]) - 1;
		param->map.content[i][len] = 0;
		if (len > max)
			max = len;
		++i;
	}
	i = 0;
	while (param->map.content[i])
	{
		len = ft_strlen(param->map.content[i]);
		param->map.content[i] = ft_realloc(param->map.content[i], len, max + 1);
		ft_memset(param->map.content[i] + len, ' ', max - len);
		param->map.content[i][max] = 0;
		++i;
	}
	param->map.len = i;
	param->map.width = max;
}

void	read_map(int fd, t_param *param)
{
	read_lines(fd, param);
	rectangular_map(param);
	validate_map(param);
	printf("valid map\n");
}