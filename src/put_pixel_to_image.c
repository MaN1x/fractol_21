/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:42:14 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:39:47 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_mlx mlx, int x, int y, unsigned int clr)
{
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
		*((unsigned int*)(mlx.img + x * sizeof(int) + y * mlx.size_line)) = clr;
}
