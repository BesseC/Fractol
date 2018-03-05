/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:44:48 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:19:29 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(void)
{
	ft_putstr("Usage : ./fractol [type de fractal]\n ");
	ft_putstr("\t\t  1 = Mandelbrot\n\t\t  2 = Julia\n\t\t  3 = Burningship\n");
	ft_putstr("\t\t  4 = Burningship Julia\n");
	exit(1);
}

void	arg_valid(int ac, char **av, t_mlx *mlx)
{
	if (ac == 2)
	{
		if (ft_atoi(av[1]) == 1)
			set_mandel(mlx);
		else if (ft_atoi(av[1]) == 2)
			set_julia(mlx);
		else if (ft_atoi(av[1]) == 3)
			set_ship(mlx);
		else if (ft_atoi(av[1]) == 4)
			set_shipjulia(mlx);
		else
			ft_usage();
	}
	else
		ft_usage();
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	arg_valid(ac, av, &mlx);
	mlx_set(&mlx);
	mlx_hook(mlx.win, 2, 0, my_key_funct, (void *)&mlx);
	mlx_mouse_hook(mlx.win, mouse_button, (void *)&mlx);
	mlx_hook(mlx.win, 6, 0, my_mouse_funct, (void *)&mlx);
	mlx_loop_hook(mlx.mlx, affichage, (void *)&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
