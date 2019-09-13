/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:36:30 by badhont           #+#    #+#             */
/*   Updated: 2018/11/27 18:16:04 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_help(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 60, PINK,
	" ESC      Quit");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 80, PINK,
	" +        Zoom In");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 100, PINK,
	" -        Zoom Out");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 120, PINK,
	" *        Z axis Up");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 140, PINK,
	" /        Z axis Down");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 160, PINK,
	" O        Zoom Optimisation");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 180, PINK,
	" ARROWS   Camera Movements");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 200, PINK,
	" SPACE    Reset settings");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 220, PINK,
	" H        Hide these commands - Repush to show");
}

/*
**	4 h
*/

void	ft_key_input(int button, t_env *env)
{
	if (button == 126)
		env->move_y += 15;
	else if (button == 124)
		env->move_x -= 15;
	else if (button == 125)
		env->move_y -= 15;
	else if (button == 123)
		env->move_x += 15;
	else if (button == 69)
		env->zoom *= 1.05;
	else if (button == 78)
		env->zoom /= 1.05;
	else if (button == 67 && env->elev < 10000)
		env->elev *= 1.07;
	else if (button == 75)
		env->elev /= 1.07;
}

/*
**	126 ^ 124 > 125 v 123 < 69 + 78 - 67 * 75 /
*/

int		ft_keyboard(int button, t_env *env)
{
	if (button == 53)
	{
		ft_free_grid(env);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (button == 49)
	{
		env->move_x = 0;
		env->move_y = 0;
		env->elev = 0.15;
		env->zoom = (WIDTH - 2 * EDGE) / (env->nb_word + env->nb_line - 2);
	}
	else if (button == 31)
		env->flag = (env->flag == 0) ? 1 : 0;
	else if (button == 4)
		env->aff_help = (env->aff_help == 0) ? 1 : 0;
	ft_key_input(button, env);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_display_grid(env);
	return (0);
}

/*
**	53 ESC 49 SPACE 31 o
*/

int		ft_exit(t_env *env)
{
	ft_free_grid(env);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(EXIT_SUCCESS);
}
