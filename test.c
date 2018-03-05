/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:31:03 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:05:41 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_deplacement(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->offset_x = mlx->offset_x - 10 / (mlx->zoom / 400);
	if (keycode == 124)
		mlx->offset_x = mlx->offset_x + 10 / (mlx->zoom / 400);
	if (keycode == 125)
		mlx->offset_y = mlx->offset_y + 10 / (mlx->zoom / 400);
	if (keycode == 126)
		mlx->offset_y = mlx->offset_y - 10 / (mlx->zoom / 400);
	if (keycode == 69)
		mlx->zoom = mlx->zoom * 1.1;
	if (keycode == 78)
		mlx->zoom = mlx->zoom / 1.1;
}

int		my_key_funct(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		free_mlx(mlx);
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78)
		ft_deplacement(keycode, mlx);
	if (keycode == 49)
		mlx->flag = !mlx->flag;
	if (keycode >= 83 && keycode <= 89)
		mlx->j = keycode - 83;
	if (keycode == 91 || keycode == 92)
		mlx->j = keycode - 91;
	return (0);
}

int		mouse_button(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->zoom = mlx->zoom * 1.1;
	if (button == 4)
		mlx->zoom = mlx->zoom / 1.1;
	return (0);
}

int		my_mouse_funct(int x, int y, t_mlx *mlx)
{
	if (mlx->flag == 1)
	{
		mlx->m_x = x * 0.001;
		mlx->m_y = y * 0.001;
	}
	return (0);
}

int		affichage(t_mlx *mlx)
{
	multi_thread(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}
