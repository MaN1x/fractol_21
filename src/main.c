/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:46:09 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:40:37 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void	choose_fractal(t_mlx *mlx, int argc, char *argv[])
{
	if (argc != 2)
		failure(WNOR);
	if (ft_strequ(argv[1], "mandelbrot"))
		mlx->frctl.formula = calc_iterates_mand;
	else if (ft_strequ(argv[1], "julia"))
		mlx->frctl.formula = calc_iterates_julia;
	else if (ft_strequ(argv[1], "mandelbrot4"))
		mlx->frctl.formula = calc_iterates_mandelbrot4;
	else
		failure(WNOR);
}

int		main(int argc, char *argv[])
{
	t_mlx			mlx;

	choose_fractal(&mlx, argc, argv);
	if (init(&mlx) == 0)
		failure(MLX_ERR);
	if (mlx.frctl.formula == calc_iterates_julia)
		mlx_hook(mlx.window, 6, 0, julia_motion, &mlx);
	draw_fractal(&mlx);
	mlx_hook(mlx.window, 2, 0, key_hook_press, &mlx);
	mlx_hook(mlx.window, 3, 0, key_hook_release, &mlx);
	mlx_hook(mlx.window, 17, 0, close, &mlx);
	mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (EXIT_SUCCESS);
}
