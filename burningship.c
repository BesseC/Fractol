/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 04:10:32 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:20:09 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_burningship(void *arg)
{
	t_complex	z;
	float		temp[4];
	int			iter;
	t_thread	*thread;

	thread = arg;
	temp[3] = thread->pix_start - 1;
	while (++temp[3] < thread->pix_end)
	{
		z.x = ((int)temp[3] % W_HEIGHT + (float)thread->mlx->offset_x *
				thread->mlx->zoom / 400 - (W_HEIGHT / 2.0)) / thread->mlx->zoom;
		z.y = (temp[3] / W_LENGHT + thread->mlx->offset_y *
				thread->mlx->zoom / 400 - (W_LENGHT / 2.0)) / thread->mlx->zoom;
		temp[0] = z.x;
		temp[1] = z.y;
		iter = -1;
		while (++iter < N_ITER && z.x * z.x + z.y * z.y < 4)
		{
			temp[2] = z.x;
			z.x = z.x * z.x - z.y * z.y + temp[0];
			z.y = 2 * fabs(temp[2] * z.y) + temp[1];
		}
		ft_color(iter, thread->mlx, temp[3]);
	}
	return (0);
}

void	*ft_burningjulia(void *arg)
{
	t_complex	z;
	float		temp[4];
	int			iter;
	t_thread	*thread;

	thread = arg;
	temp[3] = thread->pix_start - 1;
	while (++temp[3] < thread->pix_end)
	{
		z.x = ((int)temp[3] % W_HEIGHT + (float)thread->mlx->offset_x *
				thread->mlx->zoom / 400 - (W_HEIGHT / 2.0)) / thread->mlx->zoom;
		z.y = (temp[3] / W_LENGHT + thread->mlx->offset_y *
				thread->mlx->zoom / 400 - (W_LENGHT / 2.0)) / thread->mlx->zoom;
		temp[0] = z.x;
		temp[1] = z.y;
		iter = -1;
		while (++iter < N_ITER && z.x * z.x + z.y * z.y < 4)
		{
			temp[2] = z.x;
			z.x = z.x * z.x - z.y * z.y + thread->mlx->m_x;
			z.y = 2 * fabs(temp[2] * z.y) + thread->mlx->m_y;
		}
		ft_color(iter, thread->mlx, temp[3]);
	}
	return (0);
}

void	set_shipjulia(t_mlx *mlx)
{
	mlx->form = 4;
	mlx->offset_x = 5;
	mlx->offset_y = 0;
	mlx->zoom = 440.0;
}
