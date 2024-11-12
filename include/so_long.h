/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:33:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 12:50:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_ROWS 1024

# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/includes/ft_printf.h"
# include "MLX42.h"
# include <memory.h>
# include <time.h>

# define WIDTH 1920
# define HEIGHT 1080
# define T_S 32

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLEC 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'
# define MAP_ENEMY 'M'
# define MAP_EN2 'W'

# define BUFF_SIZE 10000
# define FALSE		1
# define TRUE		0
# define MOVE		T_S
# define CHAR_UP 0
# define CHAR_DOWN 1
# define CHAR_LEFT 2
# define CHAR_RIGHT 3

//ERROR CODES
# define FILE_ERROR "Error\nParamater error.\n"
# define EXT_ERROR "Error\nInvalid file extension.\n"
# define EMPTY_ERROR "Error\nMap is empty or has empty lines.\n"
# define FORM_ERROR "Error\nMap is not rectanglular.\n"
# define COMP_ERROR "Error\nWrong or missing components.\n"
# define WALL_ERROR "Error\nMap not enclosed by walls.\n"
# define ENT_ERROR "Error\nWrong entities.\n"
# define PATH_ERROR "Error\nNo valid paths.\n"
# define ALLOC_ERROR "Error\nMemory allocation failed.\n"
# define BUILD_ERROR "Error\nBuild or read fail (file exits?).\n"
# define INIT_ERROR "Error\nFailed to initialise game.\n"

//STRUCTS
typedef struct s_textu
{
	mlx_texture_t	*floor1;
	mlx_texture_t	*floor2;
	mlx_texture_t	*floor3;
	mlx_texture_t	*c_ul;
	mlx_texture_t	*c_ur;
	mlx_texture_t	*c_dl;
	mlx_texture_t	*c_dr;
	mlx_texture_t	*w_u;
	mlx_texture_t	*w_d;
	mlx_texture_t	*w_r;
	mlx_texture_t	*w_l;
	mlx_texture_t	*collec;
	mlx_texture_t	*ch[4];
	mlx_texture_t	*enem;
	mlx_texture_t	*enem2;
	mlx_texture_t	*mid;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
}				t_textu;

typedef struct s_img
{
	mlx_image_t	*floor1;
	mlx_image_t	*floor2;
	mlx_image_t	*floor3;
	mlx_image_t	*c_ul;
	mlx_image_t	*c_ur;
	mlx_image_t	*c_dl;
	mlx_image_t	*c_dr;
	mlx_image_t	*w_u;
	mlx_image_t	*w_d;
	mlx_image_t	*w_r;
	mlx_image_t	*w_l;
	mlx_image_t	*collec;
	mlx_image_t	*fch;
	mlx_image_t	*ch[4];
	mlx_image_t	*mid;
	mlx_image_t	*enem;
	mlx_image_t	*enem2;
	mlx_image_t	*exit_c;
	mlx_image_t	*exit_o;
}				t_img;

typedef struct s_point
{
	int	row;
	int	col;
	int	max_rows;
	int	max_cols;
	int	check;
}			t_point;

typedef struct s_game
{
	struct s_textu		*textu;
	struct s_img		*img;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					collec_count;
	int					move_count;
	int					n_collec;
	int					n_enem;
	char				**map_2;
}						t_game;

//INIT functions
//void		sl_cleanup_game(t_game *game);
int			sl_error(int code);
int			sl_init_game(t_game *game);
void		sl_measure_map(t_game *game, char **map);
char		**sl_load_map(char *filename);

//ENDER functions
void		sl_game_over(t_game *game);
void		sl_cleanup_game(t_game *game);
void		sl_clean_img(t_game *game);

//PARSER functions
char		**sl_map_parser(char *filename, int *rows, int *cols);
char		**sl_build_map(char *filename, char **map, int *rows, int *cols);
int			sl_handle_overflow(char *trim, char **map, int fd, int *rows);
char		*sl_read_trimmed_line(int fd);

//CHECKER functions
int			sl_checker(char **map, int rows, int cols);
int			sl_empty_checker(char **map, int rows);
int			sl_form_checker(char **map, int rows);
int			sl_enclose_checker(char **map, int rows, int cols);
int			sl_check_row_wall(char *row, int len);
int			sl_content_checker(char	**map);
int			sl_entities_checker(char **map);
int			sl_path_checker(char **map, int rows, int cols);
int			sl_ent_count(char **map);
void		sl_flood_fill(char **flood_m, t_point *char_pos, int row, int col);
int			sl_is_target(char c);
void		sl_locate_P(char **map, t_point *char_pos);
int			sl_valid_entities(char c);
void		sl_p_checker(char **map, int *p);
void		sl_e_checker(char **map, int *e);
void		sl_c_checker(char **map, int *c);
t_point		*sl_create_point(int rows, int cols);
int			sl_cleanup(t_point *char_pos, char **flood_map, int ret);

//HANDLER functions
void		sl_prep_textures(t_game *game);
void		sl_prep_imgs(t_game *game);
void		sl_delete_textures(t_game *game);
int			sl_detect_wall(t_game *game, int x, int y);
void		sl_render_wall(int index, int x, int y, t_game *game);
void		sl_render_floor(t_game *game, t_img *image);
void		sl_render_f_tile(t_game *game, int x, int y, int r);
void		sl_render_map(t_game *game, t_img *img);
void		sl_move_up(t_game *game);
void		sl_move_down(t_game *game);
void		sl_move_left(t_game *game);
void		sl_move_right(t_game *game);
void		sl_input_handler(mlx_key_data_t keydata, void *param);
int			sl_count_collec(t_game *game);
void		sl_collector(t_game *game);
void		sl_delete_collec(t_game *game);
void		sl_disable_start(t_game *game);

//BONUS functions
void		sl_write_counter(t_game *game);
void		sl_enemy_detector(t_game *game);
void		sl_render_enemy(t_game *game, int x, int y);
void		sl_move_en(t_game *game);
char		sl_detect_m(t_game *game);

#endif
