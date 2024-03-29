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
		mlx_destroy_window(mlx->instance, mlx->window);
		exit(0);
	}
	return (0);
}

int x_btn(int keycode, t_vars *mlx)
{
	printf("%p\n", mlx->img);
	printf("%s\n", "bonjour");
	mlx_destroy_image(mlx->instance, mlx->img->addr);
	printf("%s\n", "bonjour");
	mlx_clear_window(mlx->instance, mlx->window); 
	exit(keycode);
}

int change_colormod(int keycode, t_vars *mlx)
{
	printf("bonjourrrrr");
	if (keycode == ARROW_UP)
	{
		mlx->colormod += 2.314;
	}
	if (keycode == ARROW_DOWN)
		mlx->colormod -= 2.314;
	return (0);
}

int	print_mouse_pos(int x, int y, t_vars *mlx)
{
	(void) mlx;
	// return printf("%d, %d\n", x, y);
	return x + y;
}
