/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:37:46 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 16:16:16 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_number.h"
#include "fractol.h"
#include "math.h"

int		calc_iterates_julia(t_fractal fract, double x, double y)
{
	t_comp_nbr	z;
	int			i;

	i = 0;
	z = init_comp_nbr(x, y);
	while (i < fract.iterations)
	{
		z = comp_nbr_sum(comp_nbr_pow(z), fract.k);
		if (pow(z.re, 2.0) + pow(z.im, 2.0) > 4.0)
			return (i);
		i++;
	}
	return (i);
}
