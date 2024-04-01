/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:31:36 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/24 21:44:46 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

int	ft_strcmp(char *s1, char *s2)
{
	register int	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (0);
		i++;
	}
	if ((s1[i] == 0 && s2[i]) || (s1[i] && s2[i] == 0))
		return (0);
	return (1);
}

double	ft_atof(char *s)
{
	if (ft_strcmp(s, "-1"))
		return (-1.0);
	if (ft_strcmp(s, "-0.5"))
		return (-0.5);
	if (ft_strcmp(s, "0"))
		return (0.0);
	if (ft_strcmp(s, "0.5"))
		return (0.5);
	if (ft_strcmp(s, "1"))
		return (1.0);
	return (2.0);
}

double	ft_abs(double n)
{
	if (n > 0.0)
		return (n * -1.0);
	return (n);
}

void	ft_error(void)
{
	write(1, "Fool.\nOn launch, type m or 	mandelbrot \
	(not case sensitive) to show Mandelbrot.\
	\nOn launch, type b or 	burne	 \
	(not case sensitive) to show Burning Ship. \
	\nOn launch, type j or 	julia	 \
	(not case sensitive) to show Julia. \
	\nAlso you can enter two values in two separate arguments for Julia. \
	\nAccepted values are -1, -0.5, 0, 0.5, 1.\n",
		335);
}
