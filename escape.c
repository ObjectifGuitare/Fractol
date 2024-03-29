/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/24 20:48:03 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline unsigned int	striped_trgb(int iteration, t_vars *mlx)
{
	return ((0xFFFFFFFF / MAX_ITERATION) * (iteration + (mlx->colormod)));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// this offset thing is because the line length set by mlx_get_data_addr() does not correspond
	// to WINDOW_X. The value I give to offset here comes from the man but it seems to me
	// that the value of line_length should be WINDOW_X / 4... or maybe it's late and im tired
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	check_mandelship(double scaled_x, double scaled_y, double cx, double cy)
{
	double	x;
	double	y;
	double	temp;
	int		iteration;

	(void) cx;
	(void) cy;
	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y <= 4.0 && iteration++ < MAX_ITERATION)
	{
		temp = x * x - y * y + scaled_x;
		y = 2 * x * y + scaled_y;
		x = temp;
	}
	return (iteration);
}

int	check_juliaship(double x, double y, double cx, double cy)
{
	double	temp;
	int		iteration;

	iteration = 0;
	while (x * x + y * y <= 4.0 && iteration++ < MAX_ITERATION)
	{
		temp = x * x - y * y + (cx);
		y = 2 * x * y + (cy);
		x = temp;
	}
	return (iteration);
}

int	check_burning(double scaled_x, double scaled_y, double cx, double cy)
{
	double	x;
	double	y;
	double	temp;
	int		iteration;

	(void) cx;
	(void) cy;
	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y < 4.0 && iteration++ < MAX_ITERATION)
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

	screen_x = -1;
	screen_y = 0;
	while (++screen_x < WINDOW_X)
	{
		while (screen_y < WINDOW_Y)
		{
			scaled_x = -3.0 + (6.0 / WINDOW_X * (screen_x)); // min of the axis + (max of the axis / etc.)
			scaled_y = 2.0 - (4.0 / WINDOW_Y * (screen_y)); // The ratio of min-max on the axis should respect the window ratio
			my_mlx_pixel_put(mlx->img, screen_x, screen_y++,
				striped_trgb(mlx->f(scaled_x, scaled_y, mlx->cx, mlx->cy), mlx));
		}
		screen_y = 0;
	}
	return (0);
}
