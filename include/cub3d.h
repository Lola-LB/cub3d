/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 18:31:16 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MISSING_DATA "Missing data in .cub file\nIdentifiers needed : NO SO WE EA F C + map (as last element)"
# define DUPLICATE_DATA "Duplicate data in .cub file\nIdentifiers needed : NO SO WE EA F C + map (as last element)"
# define INVALID_DATA "Invalid data in .cub file"
# define MULT_START "Map contains multiple starting positions"
# define NO_START "Map does not contain any starting position"
# define NO_WALLS "Map is not surrounded by walls"
# define FORBIDDEN_CHAR "Map contains forbidden characters"
# define MALLOC_ERROR "Malloc error"
# define GNL_ERROR "Get next line error"
# define MLX_ERROR "Minilibx error"
# define FILE_ERROR "File error"
# define SYST_ERROR "System error"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define NUM_OFFSET 16
# define NB_PIXEL 70

# define MAP_LEN 50

# define W 119 //65362 //126
# define A 97  //65361 //123
# define S 115 //65364 //125
# define D 100 //65363 //124

# define XK_Escape 53
// # include <X11/keysym.h>

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_vect
{
	int		x;
	int		y;
}			t_vect;

typedef struct s_map
{
	char	**content;
	int		width;
	int		len;
}			t_map;

typedef struct s_RGB {
    int		R;
    int		G;
    int		B;
}	t_RGB;
typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_map	map;
	char	**store_data;
	char	*identifiers[6];
	t_RGB	floor_color;
	t_RGB	ceiling_color;
	t_vect	player;
	t_vect	camera;
	t_img	*texture;
	int		end_game;
}			t_param;

/* ************************************************************************** */
/*                                   main.c                                   */
/* ************************************************************************** */

void	launch_game(t_param *param);

/* ************************************************************************** */
/*                                 read_data.c                                */
/* ************************************************************************** */

void	parse_line(char *line, t_param *param);
void	parse_color(t_param *param, char *line, t_RGB color);
void	read_data(int fd, t_param *param);

/* ************************************************************************** */
/*                                  read_map.c                                */
/* ************************************************************************** */

void	read_lines(int fd, t_param *param);
void	rectangular_map(t_param *param);
void	read_map(int fd, t_param *param);

/* ************************************************************************** */
/*                               file_parsing.c                               */
/* ************************************************************************** */

void	check_extension(char *file);
void	parse_file(char *file, t_param *param);

/* ************************************************************************** */
/*                               validate_map.c                               */
/* ************************************************************************** */

void	init_player(t_param *param, int i, int j, int *start);
void	check_walls(t_param *param, int i, int j);
void	validate_map(t_param *param);

/* ************************************************************************** */
/*                   	            utils.c                                   */
/* ************************************************************************** */

void	init_param(t_param *param);
void	init_images(t_param *param);
void	ft_error(t_param *param, char *error);
int		end_game(t_param *param);

#endif