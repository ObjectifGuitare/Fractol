/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/04/02 22:36:02 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mlx(t_vars	*mlx)
{
	mlx->instance = mlx_init();
	mlx->ywin = 1000;
	mlx->xwin = 1500;
	mlx->winratio = (float) mlx->ywin / (float) mlx->xwin;
	mlx->window = mlx_new_window(mlx->instance,
			mlx->xwin, mlx->ywin, "fractol");
	// protect the malloc
	mlx->colormod = 3.2;
	mlx->zoom = 1;
	mlx->maxiter = 50;
}

void	fractol(int f(), double x, double y)
{
	t_vars	mlx;
	t_data	img;

	set_mlx(&mlx);
	img.img = mlx_new_image(mlx.instance, mlx.xwin, mlx.ywin);
	// protect the malloc
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	// protect the malloc
	mlx.img = &img;
	mlx.cx = x;
	mlx.cy = y;
	mlx.f = f;
	mlx_hook(mlx.window, ON_DESTROY, 0, x_btn, &mlx);
	mlx_loop_hook(mlx.instance, &put_fractal, &mlx);
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
