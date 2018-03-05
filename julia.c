/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 00:42:27 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:20:20 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_julia(void *arg)
{
	t_complex	z;
	float		temp;
	int			iter;
	int			i;
	t_thread	*thread;

	thread = arg;
	i = thread->pix_start - 1;
	while (++i < thread->pix_end)
	{
		z.x = (i % W_HEIGHT + (float)thread->mlx->offset_x * thread->mlx->zoom /
				400 - (W_HEIGHT / 2.0)) / thread->mlx->zoom;
		z.y = (i / W_LENGHT + thread->mlx->offset_y * thread->mlx->zoom / 400
				- (W_LENGHT / 2.0)) / thread->mlx->zoom;
		iter = -1;
		while (++iter < N_ITER && z.x * z.x + z.y * z.y < 4)
		{
			temp = z.x;
			z.x = z.x * z.x - z.y * z.y + thread->mlx->m_x;
			z.y = 2 * temp * z.y + thread->mlx->m_y;
		}
		ft_color(iter, thread->mlx, i);
	}
	return (0);
}

void	free_mlx(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < 9)
		free(mlx->color[i]);
	free(mlx->color);
	exit(1);
}
