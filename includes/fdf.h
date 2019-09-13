/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:13:26 by badhont           #+#    #+#             */
/*   Updated: 2018/11/29 21:56:33 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define PURPLE     0x7400AC
# define GREY       0x9A9A9A
# define PINK       0xFD2BE6
# define BLUE       0x0012FD
# define RED        0xFD0000
# define CYAN       0x00F3FD
# define YELLOW     0xFDF800
# define GREEN      0x05FD00
# define BROWN      0x8C4629
# define ORANGE     0xF87C00
# define WHITE      0xFFFFFF
# define BLACK      0x000000

# define WIDTH		1200
# define HEIGHT		1200
# define EDGE		100

typedef struct		s_pos
{
	int		x;
	int		y;
}					t_pos;

typedef struct		s_point
{
	t_pos	a;
	t_pos	b;
	t_pos	c;
}					t_point;

typedef	struct		s_env
{
	int		flag;
	int		aff_help;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_str;
	int		endian;
	int		bpp;
	int		s_l;
	int		nb_line;
	int		nb_word;
	float	zoom;
	float	elev;
	int		**grid;
	int		i;
	int		x;
	int		y;
	int		color;
	float	move_x;
	float	move_y;
}					t_env;

int					ft_parse(t_env *env, int fd, char *line, char *arg);
void				ft_put_value(t_env *env, char *line, int x, int y);
void				ft_get_value(t_env *env, char *line, int x);
int					ft_check_line(char *line);
int					ft_count_line(t_env *env, char *line, char *arg);
void				ft_display_grid(t_env *env);
void				ft_ibzero(int *img_str);
void				ft_place(t_env *env, int x, int y, t_pos *abc);
int					ft_keyboard(int button, t_env *env);
void				ft_key_input(int button, t_env *env);
int					ft_exit(t_env *env);
void				ft_draw_line(t_env *env, t_pos p1, t_pos p2);
void				ft_fill_pixel(t_env *env, int x, int y);
int					ft_is_in_window(t_pos p1, t_pos p2);
void				ft_draw_1(t_env *env, t_pos pos, t_pos d, t_pos inc);
void				ft_draw_2(t_env *env, t_pos pos, t_pos d, t_pos inc);
void				ft_init(t_env *env);
void				ft_free_grid(t_env *env);
void				ft_error_exit(char *str);
void				ft_print_help(t_env *env);

#endif
