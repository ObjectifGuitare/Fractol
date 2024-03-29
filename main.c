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

void	fractol(int f(), double x, double y)
{
	t_vars	mlx;
	t_data	img;

	mlx.instance = mlx_init();
	mlx.window = mlx_new_window(mlx.instance, WINDOW_X, WINDOW_Y, "fractol");
	mlx.colormod = 0;
	img.img = mlx_new_image(mlx.instance, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	
	mlx.f = f;
	mlx.img = &img;
	mlx.cx = x;
	mlx.cy = y;
	mlx.colormod = 3.2;
	put_fractal(&mlx);


	mlx_hook(mlx.window, ON_KEYDOWN, 1L<<0, change_colormod, &mlx);
	mlx_hook(mlx.window, ON_KEYDOWN, 1L<<0, ft_close, &mlx);
	mlx_hook(mlx.window, ON_DESTROY, 0, x_btn, &mlx);
	mlx_hook(mlx.window, ON_MOUSEMOVE, 1L<<6, print_mouse_pos, &mlx);
	// mlx_key_hook(mlx.window, print_mouse_pos2, &mlx);

	mlx.colormod += 3.2;
	mlx_loop_hook(mlx.instance, &put_fractal, &mlx);

	mlx_put_image_to_window(mlx.instance, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.instance);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_error();
	else if (ft_strcmp(av[1], "burn") || ft_strcmp(av[1], "b"))
		fractol(check_burning, 0, 0);
	else if (ft_strcmp(av[1], "mandelbrot") || ft_strcmp(av[1], "m"))
		fractol(check_mandelship, 0, 0);
	else if (ft_strcmp(av[1], "julia") || ft_strcmp(av[1], "j"))
	{
		if (ac == 2)
			fractol(check_juliaship, -1.0, 0.0);
		else if (ac == 4 && ft_atof(av[2]) != 2.0 && ft_atof(av[3]) != 2.0)
			fractol(check_juliaship, ft_atof(av[2]), ft_atof(av[3]));
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
