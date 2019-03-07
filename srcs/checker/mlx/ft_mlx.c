/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:24:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 21:47:37 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

void		ft_error_tmp(void)
{
	ft_printf("Error !\n");
	exit(0);
}

static void	ft_init_mlx(t_mlx *mlx, char **str, t_check *a, t_check *b)
{
	if (!(mlx->mlx = mlx_init()))
		ft_error_tmp();
	if (!(mlx->win = mlx_new_window(mlx->mlx, WINX, WINY, "Push_swap")))
		ft_error_tmp();
	if (!(mlx->img = mlx_new_image(mlx->mlx, WINX, WINY)))
		ft_error_tmp();
	ft_bzero(mlx->keyboard, sizeof(mlx->keyboard));
	mlx->canvas = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
		, &mlx->endian);
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 10;
	mlx->str = str;
	mlx->i_str = 0;
	mlx->a = a;
	mlx->b = b;
	mlx->bega = a;
	mlx->begb = b;
}

int		ft_mlx(char **str, t_check *a, t_check *b)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx, str, a, b);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
	mlx_hook(mlx.win, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_loop_hook(mlx.mlx, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
