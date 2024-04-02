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

// MAX ITERATION
# define MAX_ITERATION 100


# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	SPACE = 49,
	ESC = 53,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

typedef struct	s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_data;

typedef struct	s_vars {
	void	*instance;
	void	*window;
	float	colormod;
	int 	(*f)(double scaled_x, double scaled_y, void *mlx);
	t_data	*img;
	double	cx;
	double	cy;
	int		xwin;
	int		ywin;
	float	winratio;
	float	zoom;
	int		maxiter;
}				t_vars;

// events.c
int	ft_close(int keycode, t_vars *mlx);

int	print_mouse_pos(int x, int y, t_vars *mlx);
int x_btn(t_vars *mlx);

//utils.c
int		ft_tolower(int c);
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(char *s);
double ft_abs(double n);
void    ft_error(void);

//main.c
void	set_mlx(t_vars	*mlx);
void    fractol(int f(), double x, double y);


//escape.c
unsigned int striped_trgb(int iteration, t_vars *mlx);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	check_juliaship(double x, double y, t_vars *mlx);
int check_mandelship(double x0, double y0, t_vars *mlx);
int	check_burning(double x, double y, t_vars *mlx);
int put_fractal(t_vars *mlx);

#include <stdio.h> // for printf

#endif