/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:25:52 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 20:01:55 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "ft_checker.h"
# include "ft_keycode.h"
# include <math.h>


# define WINX 1920
# define WINY 1080

# define RES1 1000
# define RES2 1000

# define ZOOM 6

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		keyboard[256];
	void	*img;
	char	*canvas;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		zoom;
}				t_mlx;

int				ft_mlx(void);
void			ft_error_tmp(void);

void			print_square(int x, int y, t_mlx *mlx);
void			put_pixel(t_mlx *mlx, int x, int y, int color);

int				deal_key(void *param);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
#endif
