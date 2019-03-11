#ifndef FT_MLX_H
# define FT_MLX_H

# include "mlx.h"
# include "ft_checker.h"
# include "ft_keycode.h"
# include <math.h>

# define WINX 1920
# define WINY 1080
# define RES1 1000
# define RES2 1000
# define ZOOM 6

/*
** 512 car seg sinon pour ctr car code > 256
*/

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		keyboard[512];
	void	*img;
	char	*canvas;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		zoom;
	char	**str;
	int		i_str;
	int		i;
	t_check	*a;
	t_check	*b;
	t_check	*bega;
	t_check	*begb;
}				t_mlx;

void			ft_error_tmp(void);
void			print_square(int x, int y, t_mlx *mlx);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			print_stack(t_mlx *mlx);
int				deal_key(void *param);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				exite(t_mlx *mlx);
void			ft_checke_value(t_mlx **mlx);
void			ft_free_this(t_mlx **mlx);
void			ft_error_tmp(void);

#endif
