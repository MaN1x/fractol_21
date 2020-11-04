/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:19:27 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:51:34 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	init(t_mlx *mlx)
{
	if ((mlx->mlx = mlx_init()) == 0)
		return (0);
	if ((mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, TITLE)) == 0)
		return (0);
	if ((mlx->pimg = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)) == 0)
		return (0);
	mlx->img = mlx_get_data_addr(mlx->pimg, &mlx->bpp, &mlx->size_line,
																&mlx->endian);
	mlx->frctl.max_re = 2.0;
	mlx->frctl.min_re = -2.0;
	mlx->frctl.max_im = 2.0;
	mlx->frctl.min_im = -2.0;
	mlx->frctl.factor_x = (mlx->frctl.max_re - mlx->frctl.min_re) /
																(WIDTH - 1);
	mlx->frctl.factor_y = (mlx->frctl.max_im - mlx->frctl.min_im) /
																(HEIGHT - 1);
	mlx->frctl.iterations = MAX_ITERATIONS;
	mlx->julia_fixed = 0;
	return (1);
}
