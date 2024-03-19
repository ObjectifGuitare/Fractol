/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:15:16 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/19 23:02:56 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// every x point must increase by 1 / WINDOW_X * zoom_factor

void ft_escape(t_data *data)
{
    (void)data;
    double x2 = -1;
    double y2 = -1;
    int iteration = 0;
    double x;
    double y;
    double w = 0;
    double xCoor = -0.5;
    double yCoor = -1.25;
    // while(x)
    // {
    //     while(y <)
    //     {
            
    //     }
    // }
    while(x2 + y2 <= 4 && ++iteration < 1000)
    {
        x = x2 - y2 + xCoor;
        y = w - x2 - y2 + yCoor;
        x2 = x * x;
        y2 = y * y;
        w = (x + y) * (x + y);
        printf("%d iteration: %f & %f\n", iteration,x, y);
    }

}

void    color_center_pixel(t_data *img)
{
    int x = WINDOW_X * 2 / 3;
    int y = WINDOW_Y / 2;
    my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
}


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

double scale_x(int screen_x)
{
    return -2.0 + (3.0 / WINDOW_X * (screen_x));
}

double scale_y(int screen_y)
{

    return 1.12 - (2.24 / WINDOW_Y * (screen_y)); 
}

void testin(t_data *img)
{
    int screen_x = 0;
    int screen_y = 0;

    
    double x0;
    double y0;
    
    double x;
    double y;
    int iteration;
    int max_iteration = 100;
    double temp;
    while(screen_x < WINDOW_X)
    {
        while(screen_y < WINDOW_Y)
        {
            // x0 = 1 / (WINDOW_X / 3) * (screen_x + 1);
            // y0 = -1.12 / (WINDOW_Y / 2) * (screen_y + 1);
            x0 = scale_x(screen_x);
            y0 = scale_y(screen_y);
            
            x = 0.0;
            y = 0.0;
            iteration = 0;
            while(x * x + y * y <= 4 && iteration++ < max_iteration)
            {
                temp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = temp;
            }
            my_mlx_pixel_put(img, screen_x, screen_y++, trgb_iteration(iteration));
        }
        screen_x++;
        screen_y = 0;
    }
}

