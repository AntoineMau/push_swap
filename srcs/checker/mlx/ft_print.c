/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:53:39 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 19:59:00 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>
#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

static int	couleur(double t)
{
	return (RGB(127.5 * (cos(t) + 1), 127.5 * (sin(t) + 1)
		, 127.5 * (1 - cos(t))));
}

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= WINX)
		x = x % WINX;
	if (y < 0 || y >= WINY)
		y = y < 0 ? WINY + (y % WINY) : y % WINY;
	*(int *)&mlx->canvas[y * mlx->size_line + (x * 4)] = color;
}

void		print_square(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->zoom && (i = -1))
		while (++i <= mlx->zoom)
			put_pixel(mlx, x + i, y + j, couleur((i - j) * (mlx->zoom / 100)));
}
