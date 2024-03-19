/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:34 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/19 21:22:08 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// WINDOW SIZE
# define WINDOW_Y 1000
# define WINDOW_X 1500

// COLORS
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define LIGHTBLUE 0x0033FFFF
# define GREY 0x0FFFFFFF
# define ORANGE 0x00FF8000
# define DARKGREEN 0xFF00FF00



# include <mlx.h>
# include <math.h>

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
void ft_escape(t_data *data);
void    color_center_pixel(t_data *img);
void testin(t_data *img);



#include <stdio.h> // for printf
#include <stdlib.h> // for random nbr
#include <unistd.h> // for the sleep function

#endif