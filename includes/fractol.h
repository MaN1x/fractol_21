/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farctol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:07:03 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 21:22:36 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "complex_number.h"
# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fractol"
# define MAX_ITERATIONS 40
# define ITERATIONS_ADD 5
# define SATURATION 100
# define VALUE 100
# define ZOOM 1.2
# define THREADS 10

/*
** WNOR - wrong number of arguments
** MLX_ERR - mlx_init returns NULL
** MALLOC_ERR - malloc returns NULL
** PTHREAD_ERR - pthread error
*/

typedef enum	e_failures
{
	WNOR,
	MLX_ERR,
	MALLOC_ERR,
	PTHREAD_ERR
}				t_failures;

typedef struct	s_fractal
{
	double			max_im;
	double			min_im;
	double			max_re;
	double			min_re;
	double			factor_x;
	double			factor_y;
	int				start_line;
	int				finish_line;
	int				iterations;
	t_comp_nbr		k;
	int				(*formula)(struct s_fractal fract, double x, double y);
}				t_fractal;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	void		*pimg;
	char		*img;
	int			bpp;
	int			endian;
	int			size_line;
	int			julia_fixed;
	t_fractal	frctl;
}				t_mlx;

int				init(t_mlx *mlx);
void			failure(t_failures failure);
void			draw_fractal(t_mlx *mlx);
void			put_pixel_to_image(t_mlx mlx, int x, int y, unsigned int clr);
int				mouse_hook(int button, int x, int y, t_mlx *mlx);
int				calc_iterates_mand(t_fractal fract, double x, double y);
int				calc_iterates_mandelbrot4(t_fractal fract, double x, double y);
int				calc_iterates_julia(t_fractal fract, double x, double y);
int				julia_motion(int x, int y, t_mlx *mlx);
void			fractal_color(t_mlx *mlx, int x, int y, int iterates);
int				key_hook_press(int keycode, t_mlx *mlx);
int				key_hook_release(int keycode, t_mlx *mlx);
int				close(void *param);

#endif
