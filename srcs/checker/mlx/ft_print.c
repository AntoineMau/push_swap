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

void		print_square_a(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->a->nb_size * mlx->zoom && (i = -1))
		while (++i < 35)
			put_pixel(mlx, x + i, y - j, couleur(mlx->a->nb_size * 1000));
}

void		print_square_b(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->b->nb_size * mlx->zoom && (i = -1))
		while (++i < 35)
			put_pixel(mlx, x + i, y + j, couleur(mlx->b->nb_size * 1000));
}

void		print_stack(t_mlx *mlx)
{
	int		i_a;
	int		i_b;

	mlx->a = mlx->bega;
	i_a = 0;
	while (++i_a && mlx->a)
	{
		print_square_a(i_a * 35, WINY / 2 - 10, mlx);
		mlx->a = mlx->a->next;
	}
	mlx->a = mlx->bega;
	mlx->b = mlx->begb;
	i_b = 0;
	while (++i_b && mlx->b)
	{
		print_square_b(i_b * 35, (WINY / 2 + 10), mlx);
		mlx->b = mlx->b->next;
	}
	mlx->b = mlx->begb;
}
