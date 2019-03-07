/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:24:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 19:59:41 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>
#include <math.h>

void	ft_error_tmp(void)
{
	ft_printf("Error !\n");
	exit(0);
}

int		main(void)
{
	t_mlx	mlx;

	mlx.x = 0;
	mlx.y = 0;
	mlx.zoom = 100;
	ft_bzero(mlx.keyboard, sizeof(mlx.keyboard));
	if ((mlx.mlx = mlx_init()) == NULL)
		ft_error_tmp();
	if ((mlx.win = mlx_new_window(mlx.mlx, WINX, WINY, "fdf")) == NULL)
		ft_error_tmp();
	if ((mlx.img = mlx_new_image(mlx.mlx, WINX, WINY)) == NULL)
		ft_error_tmp();
	mlx.canvas = mlx_get_data_addr(mlx.img, &mlx.bpp,
		&mlx.size_line, &mlx.endian);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
	mlx_hook(mlx.win, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_loop_hook(mlx.mlx, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
