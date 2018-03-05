/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 01:59:29 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/16 08:17:03 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	multi_thread(t_mlx *mlx)
{
	pthread_t	t[N_THREAD];
	int			i;
	float		l_thread;
	t_thread	thread[N_THREAD];

	l_thread = (W_HEIGHT * W_LENGHT) / N_THREAD;
	i = -1;
	while (++i < N_THREAD)
	{
		thread[i].mlx = mlx;
		thread[i].pix_start = i * l_thread;
		thread[i].pix_end = thread[i].pix_start + l_thread;
		if (mlx->form == 1)
			pthread_create(&t[i], NULL, ft_mandelbrot, (void *)&thread[i]);
		if (mlx->form == 2)
			pthread_create(&t[i], NULL, ft_julia, (void *)&thread[i]);
		if (mlx->form == 3)
			pthread_create(&t[i], NULL, ft_burningship, (void *)&thread[i]);
		if (mlx->form == 4)
			pthread_create(&t[i], NULL, ft_burningjulia, (void *)&thread[i]);
	}
	i = -1;
	while (++i < N_THREAD)
		pthread_join(t[i], NULL);
}
