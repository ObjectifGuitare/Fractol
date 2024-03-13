/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/13 21:33:39 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    // this offset thing is because the line length set by mlx_get_data_addr() does not correspond
    // to WINDOW_X. The value I give to offset here comes from the man but it seems to me
    // that the value of line_length should be WINDOW_X / 4... or maybe it's late and im tired
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void    display_square(t_data *img)
{
    int x = 150;

    int y = 150;
    while(x < 300)
        my_mlx_pixel_put(img, x++, y, 0xAA4A44);
    
    while(y < 300)
        my_mlx_pixel_put(img, x, y++, 0xFFFFFF);
    while(x > 150)
        my_mlx_pixel_put(img, x--, y, 0xFFFF00);
    while(y > 150)
        my_mlx_pixel_put(img, x, y--, 0x0000FF);
}

void windowyes(void)
{
    
    void *mlx_instance;
    void *window;
    t_data img;

    mlx_instance = mlx_init();
    window = mlx_new_window(mlx_instance, WINDOW_X, WINDOW_X, "discover phase");
    
    img.img = mlx_new_image(mlx_instance, WINDOW_X, WINDOW_Y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    display_square(&img);
    
    mlx_put_image_to_window(mlx_instance, window, img.img, 0, 0);
    mlx_loop(mlx_instance);
}

int main()
{
    windowyes();
    return 0;
}