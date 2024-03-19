/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:11 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/19 20:29:48 by sepatez          ###   ########.fr       */
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

// the point of this function is to pack each value into a single int as 0xTTRRGGBB
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void    display_square(t_data *img)
{
    int x = 150;

    int y = 150;
    while(x < 300)
        my_mlx_pixel_put(img, x++, y, 0x00AA4A44);
    
    while(y < 300)
        my_mlx_pixel_put(img, x, y++, 0xFFFFFFFF);
    while(x > 150)
        my_mlx_pixel_put(img, x--, y, 0x00FFFF00);
    while(y > 150)
        my_mlx_pixel_put(img, x, y--, 0xFF0000FF);
}

void windowyes(void)
{
    
    void *mlx_instance;
    void *window;
    t_data img;

    mlx_instance = mlx_init();
    window = mlx_new_window(mlx_instance, WINDOW_X, WINDOW_Y, "discover phase");
    
    img.img = mlx_new_image(mlx_instance, WINDOW_X, WINDOW_Y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    // display_square(&img);
    // ft_escape(&img);
    // color_center_pixel(&img);
    testin(&img);

    mlx_put_image_to_window(mlx_instance, window, img.img, 0, 0);
    mlx_loop(mlx_instance);
}

int main()
{
    windowyes();
    // ft_escape(0x0);
//     unsigned char t = 0x91;
//     unsigned char r = 0xAB;
//     unsigned char g = 0x52;
//     unsigned char b = 0xFF;
    
//     int a = create_trgb(t, r, g, b);
   
//     a = ((0xBFF101 << 8) & 0xFF) * 10 + 1; // from now on this is the only way i'll write the number 1
//     printf("\nmy trgb is: %X\n", a);
//     printf("G channel is : %X (hexadecimal)\n", (a & 0xFF00) >> 8); // gets channel G without modifying my variable
//     printf("G channel is : %u (decimal)\n", (unsigned char)((a & 0xFF00) >> 8)); // gets channel G without modifying my variable
//     printf("G channel size is: %lu (unsigned char cast)\n", sizeof((unsigned char)((a & 0xFF00) >> 8))); // gets channel G without modifying my variable
//     printf("G channel size is: %lu\n", sizeof(((a & 0xFF00) >> 8))); // gets channel G without modifying my variable
    
//     // printf("B slot is now: %X\n", (a << 8 )& 0xFF);
    return 0;
}