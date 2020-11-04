/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:25:59 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/03 17:33:26 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hsv2rgb_p2(int hi, unsigned int v, double vinc_min[2], double a)
{
	unsigned int	rgb;

	rgb = 0;
	if (hi == 4)
		rgb = ((int)vinc_min[0] * 255 / 100) << 16 |
				((int)vinc_min[1] * 255 / 100) << 8 |
				v * 255 / 100;
	else if (hi == 5)
		rgb = (v * 255 / 100) << 16 | ((int)vinc_min[1] * 255 / 100) << 8 |
				((int)(v - a) * 255 / 100);
	return ((int)rgb);
}

static int	hsv2rgbp1(unsigned int h, unsigned int s, unsigned int v)
{
	unsigned int	rgb;
	int				hi;
	double			vinc_min[2];
	double			a;

	rgb = 0;
	hi = (int)(h / 60.0) % 6;
	vinc_min[1] = ((100 - s) * v) / 100.0;
	a = (v - vinc_min[1]) * (h % 60) / 60;
	vinc_min[0] = vinc_min[1] + a;
	if (hi == 0)
		rgb = (v * 255 / 100) << 16 | ((int)vinc_min[0] * 255 / 100) << 8 |
				(int)vinc_min[1] * 255 / 100;
	else if (hi == 1)
		rgb = (int)((v - a) * 255 / 100) << 16 | (v * 255 / 100) << 8 |
				(int)vinc_min[1] * 255 / 100;
	else if (hi == 2)
		rgb = ((int)vinc_min[1] * 255 / 100) << 16 | (v * 255 / 100) << 8 |
				(int)vinc_min[0] * 255 / 100;
	else if (hi == 3)
		rgb = ((int)vinc_min[1] * 255 / 100) << 16 | ((int)(v - a) * 255 / 100)
				<< 8 | v * 255 / 100;
	hsv2rgb_p2(hi, v, vinc_min, a);
	return ((int)rgb);
}

void		fractal_color(t_mlx *mlx, int x, int y, int iterates)
{
	int	color;

	color = hsv2rgbp1(100 * iterates / mlx->frctl.iterations, SATURATION,
iterates < mlx->frctl.iterations ? VALUE : 0);
	put_pixel_to_image(*mlx, x, y, color);
}
