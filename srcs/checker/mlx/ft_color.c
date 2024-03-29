/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:49:15 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/19 08:54:46 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

void		ft_suite_mlx(t_mlx *mlx)
{
	if ((mlx->keyboard[KEY_LEFT] == 1 && mlx->keyboard[KEY_RIGHT] == 1)
		|| (mlx->keyboard[KEY_LEFT] == 1 && mlx->keyboard[KEY_SPACEBAR] == 1))
		return ;
	mlx->keyboard[KEY_LEFT] == 1 ? (mlx->i = 0) : 0;
	mlx->keyboard[KEY_LEFT] == 1 ? mlx->i_str-- : 0;
	mlx = mlx->keyboard[KEY_RIGHT] == 1 ? tareum(mlx) : tareum_inv(mlx);
	mlx->keyboard[KEY_RIGHT] == 1 ? mlx->i_str++ : 0;
	usleep(mlx->speed * 100000);
}

double		ratio(int start, int end, int current)
{
	double	pos;
	double	distance;

	pos = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : pos / distance);
}

static int	light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int			color(int max, int nb_size)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = ratio(0, max, nb_size);
	red = light((0xFF0000 >> 16) & 0xFF, (0x0000FF >> 16) & 0xFF, percent);
	green = light((0xFF0000 >> 8) & 0xFF, (0x0000FF >> 8) & 0xFF, percent);
	blue = light(0xFF0000 & 0xFF, 0x0000FF & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
