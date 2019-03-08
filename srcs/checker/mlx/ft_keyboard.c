/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:41 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/08 17:43:44 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

int		key_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx->keyboard[key] = 1;
	return (0);
}

int		key_release(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx->keyboard[key] = 0;
	return (0);
}

static void		ft_checker_b(t_check *beginb, t_check *begina, char **str)
{
	if (beginb)
	{
		ft_free_lst(beginb);
		begina ? ft_free_lst(begina) : 0;
		ft_delstr(str, -1);
		ft_printf("KO\n");
	}
}

static t_mlx	*tareum(t_mlx *mlx)
{
	!ft_strcmp(mlx->str[mlx->i_str], "sa\n") ? ft_sa(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "sb\n") ? ft_sb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ss\n") ? ft_ss(&mlx->a, &mlx->b,
		&mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pa\n") ? ft_pa(&mlx->a, &mlx->b
		, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pb\n") ? ft_pb(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ra\n") ? ft_ra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rb\n") ? ft_rb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rr\n") ? ft_rr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rra\n") ? ft_rra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrb\n") ? ft_rrb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrr\n") ? ft_rrr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	return (mlx);
}

static t_mlx	*tareum_inv(t_mlx *mlx)
{
	!ft_strcmp(mlx->str[mlx->i_str], "sa\n") ? ft_sa(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "sb\n") ? ft_sb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ss\n") ? ft_ss(&mlx->a, &mlx->b,
		&mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pa\n") ? ft_pb(&mlx->a, &mlx->b
		, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pb\n") ? ft_pa(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ra\n") ? ft_rra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rb\n") ? ft_rrb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rr\n") ? ft_rrr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rra\n") ? ft_ra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrb\n") ? ft_rb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrr\n") ? ft_rr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	return (mlx);
}

int		deal_key(void *param)
{
	t_mlx	*mlx;
	int		tmp;

	mlx = (t_mlx *)param;
	if ((tmp = -4) && mlx->keyboard[KEY_ESC])
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if ((mlx->keyboard[KEY_RIGHT] && mlx->str[mlx->i_str][0] != 0)
		|| (mlx->keyboard[KEY_LEFT] && mlx->i_str > 0))
	{
		mlx->keyboard[KEY_LEFT] == 1 ? mlx->i_str-- : 0;
		mlx = mlx->keyboard[KEY_RIGHT] == 1 ? tareum(mlx) : tareum_inv(mlx);
		mlx->keyboard[KEY_RIGHT] == 1 ? mlx->i_str++ : 0;
		usleep(5000);
	}
	ft_bzero(mlx->canvas, 4 * WINX * WINY);
	while (!(tmp += 4) || tmp < 4 * WINX * WINY)
		*(int *)&mlx->canvas[tmp] = tmp >= 4 * WINX * (WINY / 2) && tmp < 4
			* WINX * ((WINY / 2) + 1) ? 0x00FF0000 : 0x00000000;
	print_stack(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
