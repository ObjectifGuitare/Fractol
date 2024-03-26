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
	}
	return (0);
}

int	print_mouse_pos(int x, int y, t_vars *mlx)
{
	(void) mlx;
	return printf("%d, %d\n", x, y);
}
