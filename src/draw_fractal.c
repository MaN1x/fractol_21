/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:00:57 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:49:42 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "complex_number.h"
#include "mlx.h"
#include <stdio.h>
#include "pthread.h"

static void	calc_fractal_part(t_mlx *mlx)
{
	int			i;
	int			iter;
	int			j;
	t_comp_nbr	c;

	i = 0;
	j = mlx->frctl.start_line;
	while (j < mlx->frctl.finish_line)
	{
		c.im = j * mlx->frctl.factor_y + mlx->frctl.min_im;
		while (i < WIDTH)
		{
			c.re = i * mlx->frctl.factor_x + mlx->frctl.min_re;
			iter = mlx->frctl.formula(mlx->frctl, c.re, c.im);
			fractal_color(mlx, i, j, iter);
			i++;
		}
		i = 0;
		j++;
	}
}

void		draw_fractal(t_mlx *mlx)
{
	int			i;
	pthread_t	threads[THREADS];
	t_mlx		fractal_parts[THREADS];

	i = 0;
	while (i < THREADS)
	{
		fractal_parts[i] = *mlx;
		fractal_parts[i].frctl.start_line = i * (HEIGHT / THREADS);
		fractal_parts[i].frctl.finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, (void*)&calc_fractal_part,
															&fractal_parts[i]))
			failure(PTHREAD_ERR);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL) != 0)
			failure(PTHREAD_ERR);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->pimg, 0, 0);
}
