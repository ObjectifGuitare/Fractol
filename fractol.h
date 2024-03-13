/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:34 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/13 20:59:58 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_X 500
# define WINDOW_Y 500

# include <mlx.h>
# include <math.h>


typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}               t_data;

#include <stdio.h>
#include <unistd.h> // for the sleep function

#endif