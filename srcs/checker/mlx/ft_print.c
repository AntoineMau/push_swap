/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:53:39 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 22:10:34 by anmauffr         ###   ########.fr       */
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
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int *)&mlx->canvas[y * mlx->size_line + (x * 4)] = color;
}

void		print_square(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->zoom * 50 && (i = -1))
		while (++i <= mlx->zoom)
			put_pixel(mlx, x + i, y + j, couleur(mlx->i_str));
}

void		print_stack(t_mlx *mlx)
{
	//print_square(mlx->x, mlx->y, mlx);
	int		i_a;
	int		i_b;

	mlx->a = mlx->bega;
	while (mlx->a)
	{
		ft_printf("mlx->a->n: %d\n", mlx->a->n);
		mlx->a = mlx->a->next;
	}
	ft_printf("\n\n");
	mlx->a = mlx->bega;
	i_a = 0;
	while (++i_a && mlx->a)
	{
		print_square(i_a * 10, mlx->a->n, mlx);
		mlx->a = mlx->a->next;
	}
	i_b = 0;
	while (++i_b && mlx->b)
	{
		print_square(0, (WINY / 2 + i_b * 10) + mlx->a->n, mlx);
		mlx->b = mlx->b->next;
	}
	mlx->a = mlx->bega;
	mlx->b = mlx->begb;
}
