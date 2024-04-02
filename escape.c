/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/04/02 22:49:26 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_mandelship(double scaled_x, double scaled_y, t_vars *mlx)
{
	double	x;
	double	y;
	double	temp;
	int		iteration;

	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y <= 4.0 && iteration++ < mlx->maxiter)
	{
		temp = x * x - y * y + scaled_x;
		y = 2 * x * y + scaled_y;
		x = temp;
	}
	return (iteration);
}

int	check_juliaship(double x, double y, t_vars *mlx)
{
	double	temp;
	int		iteration;

	iteration = 0;
	while (x * x + y * y <= 4.0 && iteration++ < mlx->maxiter)
	{
		temp = x * x - y * y + (mlx->cx);
		y = 2 * x * y + (mlx->cy);
		x = temp;
	}
	return (iteration);
}

int	check_burning(double scaled_x, double scaled_y, t_vars *mlx)
{
	double	x;
	double	y;
	double	temp;
	int		iteration;

	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y < 4.0 && iteration++ < mlx->maxiter)
	{
		temp = x * x - y * y + scaled_x;
		y = ft_abs(2 * x * y) + scaled_y;
		x = temp;
	}
	return (iteration);
}

int	put_fractal(t_vars *mlx)
{
	int		screen_x;
	int		screen_y;
	double	scaled_x;
	double	scaled_y;

	mlx_hook(mlx->window, ON_MOUSEDOWN, 0, mouse_trigger, mlx);
	mlx_key_hook(mlx->window, ft_close, mlx);
	screen_x = -1;
	screen_y = 0;
	while (++screen_x < mlx->xwin)
	{
		while (screen_y < mlx->ywin)
		{
			scaled_x = (-3.0 + (6.0 / mlx->xwin * (screen_x))) * mlx->zoom;
			scaled_y = (2.0 - (4.0 / mlx->ywin * (screen_y))) * mlx->zoom;
			my_mlx_pixel_put(mlx->img, screen_x, screen_y++,
				striped_trgb(mlx->f(scaled_x, scaled_y, mlx), mlx));
		}
		screen_y = 0;
	}
	mlx_put_image_to_window(mlx->instance, mlx->window, mlx->img->img, 0, 0);
	return (0);
}
