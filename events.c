/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/04/02 22:53:13 by sepatez          ###   ########.fr       */
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

int	mouse_trigger(int mousecode, int x, int y, t_vars *mlx)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mlx->zoom -= 0.05;
	if (mousecode == 5)
		mlx->zoom += 0.05;
	return (0);
}
