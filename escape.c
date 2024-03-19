/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/20 00:13:21 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int trgb_iteration(int iteration)
{
    if(iteration < 10)
        return(RED);
    if(iteration < 20)
        return(RED);
    if(iteration < 30)
        return(GREEN);
    if(iteration < 40)
        return(BLACK);
    if(iteration < 50)
        return(ORANGE);
    if(iteration < 60)
        return(ORANGE);
    if(iteration < 70)
        return(ORANGE);
    if(iteration < 80)
        return(ORANGE);
    if(iteration < 90)
        return(LIGHTBLUE);
    return (BLACK);
}

int check_mandelship(double scaled_x, double scaled_y)
{
    double x;
    double y;
    double temp;
    int iteration;

    x = 0.0;
    y = 0.0;
    iteration = 0;
    while(x * x + y * y <= 4 && iteration++ < 100)
    {
        temp = x * x - y * y + scaled_x;
        y = 2 * x * y + scaled_y;
        x = temp;
    }
    return (iteration);
}

void put_mandelbrot(t_data *img)
{
    int screen_x = -1;
    int screen_y = 0;
    double scaled_x;
    double scaled_y;

    while(++screen_x < WINDOW_X)
    {
        while(screen_y < WINDOW_Y)
        {
            scaled_x = -2.0 + (3.0 / WINDOW_X * (screen_x));
            scaled_y = 1.12 - (2.24 / WINDOW_Y * (screen_y));
            my_mlx_pixel_put(img, screen_x, screen_y++, trgb_iteration(check_mandelship(scaled_x, scaled_y)));
        }
        screen_y = 0;
    }
}

