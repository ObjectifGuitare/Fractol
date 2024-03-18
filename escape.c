/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/18 21:06:47 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_escape(t_data *data)
{
    (void)data;
    int x2 = -1;
    int y2 = -1;
    int iteration = 0;
    int x;
    int y;
    int w = 0;
    int xCoor = 250;
    int yCoor = 250;
    // while(x)
    // {
    //     while(y <)
    //     {
            
    //     }
    // }
    while(x2 + y2 <= 4 && iteration++ < 10)
    {
        x = x2 - y2 + xCoor;
        y = w - x2 - y2 + yCoor;
        x2 = x * x;
        y2 = y * y;
        w = (x + y) * (x + y);
        printf("1st iteration: %d & %d\n", x2, y2);
    }

}

void    color_center_pixel(t_data *img)
{
    int x = WINDOW_X / 2;
    int y = WINDOW_Y / 2;
    my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
}