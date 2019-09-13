/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:37:41 by badhont           #+#    #+#             */
/*   Updated: 2019/01/15 22:22:46 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	void	ft_PURPLE_pixel(t_env *env, int x, int y)
**	{
**		int	color;
**
**		color = PURPLE;
**		(void)x;
**		(void)y;
**		if ((y < HEIGHT && y > 0) && (x > 0 && x < WIDTH))
**		env->img_str[x + y * WIDTH] = PURPLE;
**	}
*/

void	ft_fill_pixel(t_env *env, int x, int y)
{
	if ((y > HEIGHT || y < 0) || (x < 0 || x > WIDTH))
		return ;
	env->img_str[x + y * WIDTH] = PURPLE;
}

int		ft_is_in_window(t_pos p1, t_pos p2)
{
	if ((p1.x < 0 || p1.x > WIDTH || p1.y < 0 || p1.y > HEIGHT)
	&& (p2.x < 0 || p2.x > WIDTH || p2.y < 0 || p2.y > HEIGHT))
		if (!(p1.y < 0 && p2.y > HEIGHT))
			if (!(p2.y < 0 && p1.y > HEIGHT))
				if (!(p1.x < 0 && p2.x > HEIGHT))
					if (!(p2.x < 0 && p1.x > HEIGHT))
						return (0);
	return (1);
}

void	ft_draw_1(t_env *env, t_pos pos, t_pos d, t_pos inc)
{
	int i;
	int	cumul;

	i = 0;
	cumul = d.x / 2;
	while (i < d.x)
	{
		pos.x += inc.x;
		cumul += d.y;
		if (cumul >= d.x)
		{
			cumul -= d.x;
			pos.y += inc.y;
		}
		ft_fill_pixel(env, pos.x, pos.y);
		i++;
	}
}

void	ft_draw_2(t_env *env, t_pos pos, t_pos d, t_pos inc)
{
	int i;
	int	cumul;

	i = 0;
	cumul = d.y / 2;
	while (i < d.y)
	{
		pos.y += inc.y;
		cumul += d.x;
		if (cumul >= d.y)
		{
			cumul -= d.y;
			pos.x += inc.x;
		}
		ft_fill_pixel(env, pos.x, pos.y);
		i++;
	}
}

void	ft_draw_line(t_env *env, t_pos p1, t_pos p2)
{
	t_pos	d;
	t_pos	inc;
	t_pos	pos;

	if (env->flag == 1 && !ft_is_in_window(p1, p2))
		return ;
	pos.x = p1.x;
	pos.y = p1.y;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x *= inc.x;
	d.y *= inc.y;
	ft_fill_pixel(env, pos.x, pos.y);
	if (d.x > d.y)
		ft_draw_1(env, pos, d, inc);
	else
		ft_draw_2(env, pos, d, inc);
}
