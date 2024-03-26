/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:34 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/24 21:44:37 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// WINDOW SIZE
# define WINDOW_Y 1000
# define WINDOW_X 1500

// MAX ITERATION - should maybe not be a macro
# define MAX_ITERATION 100

// KEYCODES
# define ESC 53
# define SPACE 49


# include <mlx.h>
# include <unistd.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}               t_data;

typedef struct	s_vars {
	void	*instance;
	void	*window;
}				t_vars;

// events.c
int	ft_close(int keycode, t_vars *mlx);
int	print_mouse_pos(int x, int y, t_vars *mlx);

//utils.c
int		ft_tolower(int c);
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(char *s);
double ft_abs(double n);
void    ft_error(void);

//main.c
void    fractol(int f(), double x, double y);


//escape.c
unsigned int striped_trgb(int iteration);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	check_juliaship(double x, double y, double cx, double cy);
int check_mandelship(double x0, double y0, double cx, double cy);
int	check_burning(double x, double y, double cx, double cy);
void put_fractal(t_data *img, int f(), double cx, double cy);




#include <stdio.h> // for printf

#endif