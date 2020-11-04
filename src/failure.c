/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:55:48 by mjoss             #+#    #+#             */
/*   Updated: 2020/11/02 20:04:03 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

void	failure(t_failures failure)
{
	if (failure == WNOR)
	{
		ft_putendl("wrong number of arguments");
		ft_putendl("usage: fractol [mandelbrot | julia | mandelbrot4]");
		exit(EXIT_SUCCESS);
	}
	else if (failure == MLX_ERR)
	{
		ft_putendl("mlx error");
		exit(EXIT_FAILURE);
	}
	else if (failure == MALLOC_ERR)
	{
		ft_putendl("Not enough memory (malloc return NULL)");
		exit(EXIT_FAILURE);
	}
	else if (failure == PTHREAD_ERR)
	{
		ft_putendl("Pthread returns not 0");
		exit(EXIT_FAILURE);
	}
}
