/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:44:29 by badhont           #+#    #+#             */
/*   Updated: 2019/01/12 16:03:59 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_value(t_env *env, char *line, int x, int y)
{
	int value;

	value = ft_atoi(line);
	if (value >= -1000 && value <= 1000)
		env->grid[x][y] = value;
	else
		env->grid[x][y] = (value > 1000) ? 1000 : -1000;
}

/*
**	Max 1000 - Min -1000
*/

void	ft_get_value(t_env *env, char *line, int x)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			ft_put_value(env, line + i, x, y);
		while (line[i] && line[i] != ' ')
			i++;
		y++;
	}
}

int		ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
		{
			if (line[i + 1] && !ft_isdigit(line[i + 1]))
				return (0);
			i++;
		}
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		ft_count_line(t_env *env, char *line, char *arg)
{
	int	ret;
	int	fd;
	int	size;
	int	valid;

	size = 0;
	valid = 0;
	if (!(fd = open(arg, O_RDONLY)))
		return (0);
	while ((ret = get_next_line(fd, &line) == 1))
	{
		valid = 1;
		size = (size == 0) ? ft_countwords(line, ' ') : size;
		if (ft_countwords(line, ' ') != size)
			ft_error_exit("Error : unequal line size");
		if (ft_check_line(line) == 0)
			ft_error_exit("Error : invalid value");
		env->nb_line++;
		free(line);
	}
	if (valid == 0)
		ft_error_exit("Error : wrong map file");
	free(line);
	close(fd);
	return (1);
}

int		ft_parse(t_env *env, int fd, char *line, char *arg)
{
	int		x;

	if (!ft_count_line(env, line, arg))
		return (0);
	if (!(env->grid = (int **)malloc(sizeof(int *) * env->nb_line)))
		ft_error_exit("Error : malloc 1 didn't work in ft_parse");
	x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		env->nb_word = ft_countwords(line, ' ');
		if (!(env->grid[x] = (int *)malloc(sizeof(int) * env->nb_word)))
			ft_error_exit("Error : malloc 2 didn't work in ft_parse");
		ft_get_value(env, line, x);
		x++;
		free(line);
	}
	free(line);
	return (1);
}
