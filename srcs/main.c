/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:11:07 by badhont           #+#    #+#             */
/*   Updated: 2018/11/23 17:01:53 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_env *env)
{
	env->move_x = 1;
	env->move_y = 1;
	env->elev = 0.15;
	env->nb_line = 0;
	env->flag = 0;
	env->aff_help = 1;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "fdf");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
}

void	ft_free_grid(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_line)
	{
		free(env->grid[i]);
		i++;
	}
	free(env->grid);
}

void	ft_error_exit(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_env	env;

	line = 0;
	ft_init(&env);
	if (ac != 2)
		ft_error_exit("Error : wrong numbers of arguments");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error_exit("Error : can't open");
	if (!(ft_parse(&env, fd, line, av[1])))
		ft_error_exit("Error : invalid value");
	close(fd);
	if (!(env.img_str = (int *)mlx_get_data_addr(env.img_ptr, &(env.bpp),
	&(env.s_l), &(env.endian))))
		ft_error_exit("Error : can't get the data address");
	mlx_hook(env.win_ptr, 2, 0, ft_keyboard, &env);
	mlx_hook(env.win_ptr, 17, 0, ft_exit, &env);
	env.zoom = (WIDTH - 2 * EDGE) / (env.nb_word + env.nb_line);
	ft_display_grid(&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
