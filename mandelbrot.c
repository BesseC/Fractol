/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:42:52 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:07:06 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_tcouleur(int color1, int color2, int n, int i)
{
	int c1[3];
	int c2[3];
	int r;
	int v;
	int b;

	c1[0] = (color1 & 0xFF0000) / (256 * 256);
	c2[0] = (color2 & 0xFF0000) / (256 * 256);
	c1[1] = (color1 & 0x00FF00) / 256;
	c2[1] = (color2 & 0x00FF00) / 256;
	c1[2] = color1 & 0x0000FF;
	c2[2] = color2 & 0x0000FF;
	r = ((c1[0] * i + c2[0] * (n - i)) / n);
	v = ((c1[1] * i + c2[1] * (n - i)) / n);
	b = ((c1[2] * i + c2[2] * (n - i)) / n);
	return (r * 256 * 256 + v * 256 + b);
}

void	ft_color(int iter, t_mlx *mlx, int i)
{
	int c;

	if (iter == N_ITER)
		mlx->img.data[i] = mlx->color[mlx->j][0];
	else if (iter >= N_ITER / 2)
	{
		c = ft_tcouleur(mlx->color[mlx->j][1], mlx->color[mlx->j][2],
				N_ITER, iter);
		mlx->img.data[i] = c;
	}
	else
	{
		c = ft_tcouleur(mlx->color[mlx->j][3], mlx->color[mlx->j][4],
				N_ITER / 2, iter);
		mlx->img.data[i] = c;
	}
}

void	*ft_mandelbrot(void *arg)
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
		z.y = (temp[3] / W_LENGHT + thread->mlx->offset_y * thread->mlx->zoom
				/ 400 - (W_LENGHT / 2.0)) / thread->mlx->zoom;
		temp[0] = z.x;
		temp[1] = z.y;
		iter = -1;
		while (++iter < N_ITER && z.x * z.x + z.y * z.y < 4)
		{
			temp[2] = z.x;
			z.x = z.x * z.x - z.y * z.y + temp[0];
			z.y = 2 * temp[2] * z.y + temp[1];
		}
		ft_color(iter, thread->mlx, temp[3]);
	}
	return (0);
}

void	set_color2(t_mlx *mlx)
{
	mlx->color[1][0] = COLOR6;
	mlx->color[1][1] = COLOR7;
	mlx->color[1][2] = COLOR8;
	mlx->color[1][3] = COLOR9;
	mlx->color[1][4] = COLOR10;
	mlx->color[2][0] = COLOR11;
	mlx->color[2][1] = COLOR12;
	mlx->color[2][2] = COLOR13;
	mlx->color[2][3] = COLOR14;
	mlx->color[2][4] = COLOR15;
	mlx->color[3][0] = COLOR16;
	mlx->color[3][1] = COLOR17;
	mlx->color[3][2] = COLOR18;
	mlx->color[3][3] = COLOR19;
	mlx->color[3][4] = COLOR20;
	mlx->color[4][0] = COLOR21;
	mlx->color[4][1] = COLOR22;
	mlx->color[4][2] = COLOR23;
	mlx->color[4][3] = COLOR24;
	mlx->color[4][4] = COLOR25;
	mlx->color[5][0] = COLOR26;
	mlx->color[5][1] = COLOR27;
	mlx->color[5][2] = COLOR28;
	mlx->color[5][3] = COLOR29;
	mlx->color[5][4] = COLOR30;
}

void	set_color3(t_mlx *mlx)
{
	mlx->color[6][0] = COLOR31;
	mlx->color[6][1] = COLOR32;
	mlx->color[6][2] = COLOR33;
	mlx->color[6][3] = COLOR34;
	mlx->color[6][4] = COLOR35;
	mlx->color[7][0] = COLOR36;
	mlx->color[7][1] = COLOR37;
	mlx->color[7][2] = COLOR38;
	mlx->color[7][3] = COLOR39;
	mlx->color[7][4] = COLOR40;
	mlx->color[8][0] = COLOR41;
	mlx->color[8][1] = COLOR42;
	mlx->color[8][2] = COLOR43;
	mlx->color[8][3] = COLOR44;
	mlx->color[8][4] = COLOR45;
}
