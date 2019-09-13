/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:25:58 by badhont           #+#    #+#             */
/*   Updated: 2018/11/28 20:45:02 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_ibzero(int *img_str)
{
	int i;

	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		img_str[i] = 0;
		i++;
	}
}

void	ft_place(t_env *env, int x, int y, t_pos *abc)
{
	abc->x = (x - y + env->nb_line / 2 - env->nb_word / 2)
		* env->zoom + WIDTH / 2 + env->move_x;
	abc->y = (x + y - env->nb_line / 2 - env->nb_word / 2 - env->grid[y][x]
		* env->elev) * env->zoom / 2 + HEIGHT / 2 + env->move_y;
}

void	ft_display_grid(t_env *env)
{
	t_point		point;

	ft_ibzero(env->img_str);
	env->y = -1;
	while (++env->y < env->nb_line)
	{
		env->x = -1;
		while (++env->x < env->nb_word)
		{
			ft_place(env, env->x, env->y, &point.a);
			if (env->x < (env->nb_word - 1))
			{
				ft_place(env, env->x + 1, env->y, &point.b);
				ft_draw_line(env, point.a, point.b);
			}
			if (env->y < (env->nb_line - 1))
			{
				ft_place(env, env->x, env->y + 1, &point.c);
				ft_draw_line(env, point.a, point.c);
			}
		}
	}
	mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
	if (env->aff_help == 1)
		ft_print_help(env);
}
