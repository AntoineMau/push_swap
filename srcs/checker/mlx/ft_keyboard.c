/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:41 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 20:01:28 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

int		key_press(int key, void *param)
{
	t_mlx *pmlx;

	ft_putnbr(key);
	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 1;
	return (0);
}

int		key_release(int key, void *param)
{
	t_mlx *pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 0;
	return (0);
}

int		deal_key(void *param)
{
	t_mlx	*pmlx;
	int		i;

	pmlx = (t_mlx *)param;
	if (pmlx->keyboard[KEY_ESC])
	{
		mlx_destroy_image(pmlx->mlx, pmlx->img);
		mlx_destroy_window(pmlx->mlx, pmlx->win);
		exit(0);
	}
	if (pmlx->keyboard[KEY_RIGHT] || pmlx->keyboard[KEY_LEFT])
		pmlx->x += (pmlx->keyboard[KEY_RIGHT] - pmlx->keyboard[KEY_LEFT]) * 20;
	ft_bzero(pmlx->canvas, 4 * WINX * WINY);
	i = 0;
	while (i < 4 * WINX * WINY)
		*(int *)&pmlx->canvas[(i += 4)] = 0x00D3D3D3;
	print_square(pmlx->x, pmlx->y, pmlx);
	mlx_put_image_to_window(pmlx->mlx, pmlx->win, pmlx->img, 0, 0);
	return (0);
}
