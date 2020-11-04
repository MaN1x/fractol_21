/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:30:16 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:55:41 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "complex_number.h"
#include "keymap.h"
#include <stdlib.h>
#include <limits.h>

static double	interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

int				mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	double		scale;
	t_comp_nbr	mouse_pos;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		scale = button == MOUSE_SCROLL_UP ? 1.0 / ZOOM : 1.0 * ZOOM;
		mouse_pos = init_comp_nbr(x * mlx->frctl.factor_x +
				mlx->frctl.min_re, y * mlx->frctl.factor_y +
														mlx->frctl.min_im);
		mlx->frctl.max_re = interpolate(mouse_pos.re, mlx->frctl.max_re, scale);
		mlx->frctl.min_re = interpolate(mouse_pos.re, mlx->frctl.min_re, scale);
		mlx->frctl.max_im = interpolate(mouse_pos.im, mlx->frctl.max_im, scale);
		mlx->frctl.min_im = interpolate(mouse_pos.im, mlx->frctl.min_im, scale);
		mlx->frctl.factor_x = (mlx->frctl.max_re - mlx->frctl.min_re) /
																(WIDTH - 1);
		mlx->frctl.factor_y = (mlx->frctl.max_im - mlx->frctl.min_im) /
																(HEIGHT - 1);
		draw_fractal(mlx);
	}
	return (0);
}

int				julia_motion(int x, int y, t_mlx *mlx)
{
	if (mlx->julia_fixed == 0)
		mlx->frctl.k = init_comp_nbr(x * mlx->frctl.factor_x +
						mlx->frctl.min_re, y * mlx->frctl.factor_y +
														mlx->frctl.min_im);
	draw_fractal(mlx);
	return (0);
}

int				key_hook_press(int keycode, t_mlx *mlx)
{
	if (keycode == MAIN_PAD_PLUS || keycode == NUM_PAD_PLUS)
	{
		mlx->frctl.iterations += mlx->frctl.iterations == INT_MAX ? 0 :
																ITERATIONS_ADD;
		draw_fractal(mlx);
	}
	else if (keycode == MAIN_PAD_MINUS || keycode == NUM_PAD_MINUS)
	{
		mlx->frctl.iterations -= mlx->frctl.iterations - ITERATIONS_ADD <= 0 ?
															0 : ITERATIONS_ADD;
		draw_fractal(mlx);
	}
	return (0);
}

int				key_hook_release(int keycode, t_mlx *mlx)
{
	if (keycode == ESC && mlx)
		exit(EXIT_SUCCESS);
	else if (keycode == SPACE)
		mlx->julia_fixed = mlx->julia_fixed == 0 ? 1 : 0;
	return (0);
}
