/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:34 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/20 19:38:56 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// WINDOW SIZE
# define WINDOW_Y 1000
# define WINDOW_X 1500

// MAX ITERATION - should maybe not be a macro
# define MAX_ITERATION 596

// COLORS
# define COLOR_FACTOR 1.36

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define LIGHTBLUE 0x0033FFFF
# define GREY 0x96FFFFFF
# define ORANGE 0x00FF8000
# define DARKGREEN 0xFF00FF00



# include <mlx.h>

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}               t_data;


//truc.c
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void    display_square(t_data *img);
void windowyes(void);

//escape.c


unsigned int striped_trgb(int iteration);
int check_mandelship(double x0, double y0);
void put_mandelbrot(t_data *img);



#include <stdio.h> // for printf

#endif