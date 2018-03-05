/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:27:34 by cbesse            #+#    #+#             */
/*   Updated: 2018/01/22 15:24:50 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** pallette 1
** ensemble = COLOR1
** De COLOR2 vers COLOR3 puis de COLOR4 vers COLOR5
*/

# define COLOR1 0xbbbb00
# define COLOR2 0xff0000
# define COLOR3 0xffff00
# define COLOR4 0x00FF2E2E
# define COLOR5 0x00333333

/*
** pallette 2
** ensemble = COLOR6
** De COLOR7 vers COLOR8 puis de COLOR9 vers COLOR10
*/
# define COLOR6 0x000000
# define COLOR7 0x000077
# define COLOR8 0x0000ff
# define COLOR9 0x0000ff
# define COLOR10 0x000000

/*
** pallette 3
** ensemble = COLOR11
** De COLOR12 vers COLOR13 puis de COLOR14 vers COLOR15
*/
# define COLOR11 0xffffff
# define COLOR12 0xB0E163
# define COLOR13 0x07E18F
# define COLOR14 0x07E18F
# define COLOR15 0x1260E1

/*
** pallette 4
** ensemble = COLOR16
** De COLOR17 vers COLOR18 puis de COLOR19 vers COLOR20
*/
# define COLOR16 0x000000
# define COLOR17 0x0002E1
# define COLOR18 0xffffff
# define COLOR19 0xE1D700
# define COLOR20 0xD38AFF

/*
** pallette 5
** ensemble = COLOR21
** De COLOR22 vers COLOR23 puis de COLOR24 vers COLOR25
*/
# define COLOR21 0x000000
# define COLOR22 0xff0000
# define COLOR23 0x777700
# define COLOR24 0x777700
# define COLOR25 0x00ff00

/*
** pallette 6
** ensemble = COLOR26
** De COLOR27 vers COLOR28 puis de COLOR29 vers COLOR30
*/
# define COLOR26 0x000000
# define COLOR27 0x000077
# define COLOR28 0x0000ff
# define COLOR29 0x0000ff
# define COLOR30 0x000000

/*
** pallette 7
** ensemble = COLOR31
** De COLOR32 vers COLOR33 puis de COLOR34 vers COLOR35
*/
# define COLOR31 0xbbbb00
# define COLOR32 0xff0000
# define COLOR33 0xffff00
# define COLOR34 0xFF2E2E
# define COLOR35 0x333333

/*
** pallette 8
** ensemble = COLOR36
** De COLOR37 vers COLOR38 puis de COLOR39 vers COLOR40
*/
# define COLOR36 0xbbbb00
# define COLOR37 0xff0000
# define COLOR38 0xffff00
# define COLOR39 0xFF2E2E
# define COLOR40 0x333333

/*
** pallette 9
** ensemble = COLOR41
** De COLOR42 vers COLOR43 puis de COLOR44 vers COLOR45
*/
# define COLOR41 0xbbbb00
# define COLOR42 0xff0000
# define COLOR43 0xffff00
# define COLOR44 0xFF2E2E
# define COLOR45 0x333333
# include "mlx.h"
# include "libft/includes/libft.h"
# include <pthread.h>
# include <math.h>
# define W_HEIGHT 1024
# define W_LENGHT 1024
# define N_THREAD 256
# define N_ITER 128

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;
typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	float	offset_x;
	float	offset_y;
	float	zoom;
	float	m_x;
	float	m_y;
	int		form;
	int		flag;
	int		**color;
	int		j;
}				t_mlx;
typedef struct	s_thread
{
	t_mlx	*mlx;
	int		pix_start;
	int		pix_end;
}				t_thread;
typedef struct	s_complex
{
	float	x;
	float	y;
}				t_complex;
void			*ft_mandelbrot(void *arg);
void			ft_color(int iter, t_mlx *mlx, int i);
void			*ft_julia(void *arg);
void			ft_clearsc(t_mlx *mlx);
void			multi_thread(t_mlx *mlx);
void			*ft_burningship(void *arg);
void			ft_deplacement(int keycode, t_mlx *mlx);
int				my_key_funct(int keycode, t_mlx *mlx);
int				mouse_button(int button, int x, int y, t_mlx *mlx);
int				my_mouse_funct(int x, int y, t_mlx *mlx);
int				affichage(t_mlx *mlx);
void			mlx_set(t_mlx *mlx);
void			set_ship(t_mlx *mlx);
void			set_julia(t_mlx *mlx);
void			set_mandel(t_mlx *mlx);
void			set_color2(t_mlx *mlx);
void			set_color3(t_mlx *mlx);
void			free_mlx(t_mlx *mlx);
void			*ft_burningjulia(void *arg);
void			set_shipjulia(t_mlx *mlx);
#endif
