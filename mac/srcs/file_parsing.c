/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:26:01 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/27 12:43:44 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(".cub", file + len - 4) != 0)
		ft_error(NULL, "Map file must end with a .cub extension");
}

void	parse_file(char *file, t_data *data)
{
	int		fd;

	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(data, FILE_ERROR);
	read_data(fd, data);
	read_map(fd, data);
}
