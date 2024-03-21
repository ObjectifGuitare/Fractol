/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/21 19:56:45 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



inline unsigned int striped_trgb(int iteration)
{
	return (0xFFFFFFFF / MAX_ITERATION) * (iteration - COLOR_FACTOR);
}

int	check_mandelship(double scaled_x, double scaled_y)
{
	double	x;
	double	y;
	double	temp;
	int		iteration;

	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y <= 4 && iteration++ < MAX_ITERATION)
	{
		temp = x * x - y * y + scaled_x;
		y = 2 * x * y + scaled_y;
		x = temp;
	}
	return (iteration);
}

char	check_abs(double x, double y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if(x + y > 16)
		return (0);
	return (1);
}

int	check_juliaship(double x, double y)
{
	double	temp;
	int		iteration;

	iteration = 0;
	while(check_abs(x, y) && iteration++ < MAX_ITERATION)
	{
		// temp = x;
		// x = x * x - y * y - 0.75;
		// y = 2.0 * temp * y + 0.025;

		temp = x * x - y * y - 1.75;
		y = 2 * x * y + 0.025;
		x = temp;
	}
	return (iteration);
}

void	put_mandelbrot(t_data *img)
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
			scaled_x = -3.0 + (6.0 / WINDOW_X * (screen_x));
			scaled_y = 2.24 - (4.48 / WINDOW_Y * (screen_y));
			my_mlx_pixel_put(img, screen_x, screen_y++,
				striped_trgb(MEMBERSHIP(scaled_x, scaled_y)));
		}
		screen_y = 0;
	}
}
