/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:39:22 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:08:42 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_mlx *mlx)
{
	int i;

	i = -1;
	if (!(mlx->color = (int **)ft_memalloc(sizeof(int *) * 9)))
		return ;
	while (++i < 9)
	{
		if (!(mlx->color[i] = (int *)ft_memalloc(sizeof(int) * 5)))
			return ;
	}
	mlx->color[0][0] = COLOR1;
	mlx->color[0][1] = COLOR2;
	mlx->color[0][2] = COLOR3;
	mlx->color[0][3] = COLOR4;
	mlx->color[0][4] = COLOR5;
	set_color2(mlx);
	set_color3(mlx);
}

void	mlx_set(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W_HEIGHT, W_LENGHT, "Fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, W_HEIGHT, W_LENGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	mlx->flag = 1;
	mlx->j = 0;
	set_color(mlx);
}

void	set_mandel(t_mlx *mlx)
{
	mlx->form = 1;
	mlx->offset_x = -300;
	mlx->offset_y = 0;
	mlx->zoom = 400.0;
}

void	set_julia(t_mlx *mlx)
{
	mlx->form = 2;
	mlx->offset_x = 5;
	mlx->offset_y = 0;
	mlx->zoom = 440.0;
}

void	set_ship(t_mlx *mlx)
{
	mlx->form = 3;
	mlx->offset_x = -708;
	mlx->offset_y = -12;
	mlx->zoom = 7677.0;
}
