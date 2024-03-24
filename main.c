/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/24 21:40:49 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// this offset thing is because the line length set by mlx_get_data_addr() does not correspond
	// to WINDOW_X. The value I give to offset here comes from the man but it seems to me
	// that the value of line_length should be WINDOW_X / 4... or maybe it's late and im tired
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	fractol(char **av, int f())
{
	void	*mlx_instance;
	void	*window;
	t_data	img;

	(void) av;
	mlx_instance = mlx_init();
	window = mlx_new_window(mlx_instance, WINDOW_X, WINDOW_Y, "discover phase");
	img.img = mlx_new_image(mlx_instance, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	put_fractal(&img, f);
	mlx_put_image_to_window(mlx_instance, window, img.img, 0, 0);
	mlx_loop(mlx_instance);
}

void	ft_error(void)
{
	write(1, "Fool.\nOn launch, type m or 	mandelbrot \
	(not case sensitive) to show mandelbrot.\
	\nOn launch, type j or 	julia	 \
	(not case sensitive) to show Julia. \
	\nAlso you can enter two floats in two separate arguments for Julia.\n",
	217);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_error();
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") || ft_strcmp(av[1], "m"))
	{
		fractol(av, check_mandelship);
		return (0);
	}
	else if (ft_strcmp(av[1], "julia") || ft_strcmp(av[1], "j"))
	{
		if (ac == 2)
			fractol(av, check_juliaship);

		return (0);
	}
	else
		ft_error();
}
