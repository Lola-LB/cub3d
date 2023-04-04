/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/04 19:03:57 by lle-bret         ###   ########.fr       */
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

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 800

# define NUM_OFFSET 16
# define NB_PIXEL 70

# define MAP_LEN 50

// LINUX
# define W 119 //65362
# define A 97  //65361
# define S 115 //65364
# define D 100 //65363
# define DEBUG 32
# define LEFT 65361
# define RIGHT 65363

// // MAC
// # define W 126
// # define A 123
// # define S 125
// # define D 124
// # define DEBUG 49
// # define LEFT 12
// # define RIGHT 13

# define NO 0
# define SO 1 
# define WE 2
# define EA 3

// # define XK_Escape 53 // MAX
# include <X11/keysym.h> // LINUX

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_int_vect
{
	int				x;
	int				y;
}					t_int_vect;

typedef struct s_double_vect
{
	double			x;
	double			y;
}					t_double_vect;

typedef struct s_map
{
	char			**content;
	int				width;
	int				len;
}					t_map;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_raycaster {
    t_double_vect	player;
    t_int_vect		square;
	t_double_vect	dir;
	t_double_vect	plane;
	t_double_vect	step;
	t_double_vect	rayDir;
	t_double_vect	sideDist;
	t_double_vect	deltaDist;
	t_double_vect	rot;
	double			perp_wall_dist;
	double			camera_x;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_raycaster;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			*map;
	char			**store_data;
	char			*identifiers[6];
	int				floor_color;
	int				ceiling_color;
	t_img			*texture;
	t_img			*screen;
	t_raycaster		*rc;
	double			move_speed;
	double			rotate_speed;
}					t_data;

/* ************************************************************************** */
/*                                   main.c                                   */
/* ************************************************************************** */

void			launch_game(t_data *data);

/* ************************************************************************** */
/*                               file_parsing.c                               */
/* ************************************************************************** */

void			check_extension(char *file);
void			parse_file(char *file, t_data *data);

/* ************************************************************************** */
/*                                 read_data.c                                */
/* ************************************************************************** */

void			parse_line(char *line, t_data *data);
int				parse_color(t_data *data, char *line);
void			read_data(int fd, t_data *data);

/* ************************************************************************** */
/*                                  read_map.c                                */
/* ************************************************************************** */

int				read_lines(t_data *data, int fd, char *line, int *len);
void			read_content(int fd, t_data *data);
void			rectangular_map(t_data *data);
void			read_map(int fd, t_data *data);

/* ************************************************************************** */
/*                               validate_map.c                               */
/* ************************************************************************** */

void			init_player(t_data *data, int i, int j, int *start);
void			check_walls(t_data *data, int i, int j);
void			validate_position(t_data *data, int i, int j, int *start);
void			validate_map(t_data *data);

/* ************************************************************************** */
/*                   	            init.c                                    */
/* ************************************************************************** */

void			init_data(t_data *data);
void			init_images(t_data *data);
void			init_screen(t_data *data);

/* ************************************************************************** */
/*                                raycaster.c                                 */
/* ************************************************************************** */

void			follow_ray(t_data *data);
void			draw_ver_line(t_data *data, int screenX);
void			raycaster(t_data *data, int start, int end);

/* ************************************************************************** */
/*                             raycaster_draw.c                               */
/* ************************************************************************** */

void			img_pixel_put(t_img *img, int x, int y, int color);
t_img			*get_texture(t_data *data);
t_int_vect		get_tex_coord(t_data *data, t_img texture);
void			img_ver_line_put(t_data *data, t_img *texture, int screenX, int y);

/* ************************************************************************** */
/*                   	        vect_operations.c                             */
/* ************************************************************************** */

t_double_vect	scalar_mult(t_double_vect v, double lambda);
t_double_vect	vect_sum(t_double_vect u, t_double_vect v);
t_double_vect	set_vect(double x, double y);
t_double_vect	set_step(t_double_vect v);
t_double_vect	rotate_vect(t_data *data, t_double_vect vect, int left);

/* ************************************************************************** */
/*                   	        	 events.c                                 */
/* ************************************************************************** */

int				check_move(t_data *data, t_double_vect newPos);
void			move_player(int keysym, t_data *data);
void			shift_screen(t_data *data, int left);
void			rotate_view(int keysym, t_data *data);
int				handle_key(int keysym, t_data *data);

/* ************************************************************************** */
/*                   	             end.c                                    */
/* ************************************************************************** */

void			free_map(t_map *map);
void			ft_error(t_data *data, char *error);
int				end_game(t_data *data);

/* ************************************************************************** */
/*                   	             debug.c                                  */
/* ************************************************************************** */

void			print_map(t_data *data);
void			print_vect(t_double_vect v);
void			print_rc(t_data *data);
void			print_img(t_img *img);
void			print_adresses(t_data *data);

#endif