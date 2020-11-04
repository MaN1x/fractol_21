/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:20:39 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 16:52:04 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int		calc_iterates_mand(t_fractal fract, double x, double y)
{
	t_comp_nbr	z;
	t_comp_nbr	c;
	int			i;

	i = 0;
	z = init_comp_nbr(0, 0);
	c = init_comp_nbr(x, y);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0 && i++ != fract.iterations)
		z = comp_nbr_sum(comp_nbr_pow(z), c);
	return (i);
}
