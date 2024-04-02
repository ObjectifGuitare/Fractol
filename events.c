/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/24 21:40:49 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keycode, t_vars *mlx)
{
	if (keycode == ESC)
	{
		free(mlx->img->addr);
		if (mlx->instance && mlx->window)
			mlx_clear_window(mlx->instance, mlx->window);
		if (mlx->instance && mlx->window)
			mlx_destroy_window(mlx->instance, mlx->window); 
		exit(0);
	}
	if (keycode == 126)
		mlx->colormod += 0.314;
	if (keycode == 125)
		mlx->colormod -= 0.314;
	if (keycode == 4)
		mlx->zoom -= 0.05;
	if (keycode == 5)
		mlx->zoom += 0.05;
	
	printf("%d\n", keycode);
	return (0);
}

int	x_btn(t_vars *mlx)
{
	free(mlx->img->addr);
	if (mlx->instance && mlx->window)
		mlx_clear_window(mlx->instance, mlx->window);
	if (mlx->instance && mlx->window)
		mlx_destroy_window(mlx->instance, mlx->window); 
	exit(0);
}


int	print_mouse_pos(int x, int y, t_vars *mlx)
{
	(void) mlx;
	return (x + y);
}
