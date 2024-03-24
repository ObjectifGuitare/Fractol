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
	register int    i;

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

double	atof(char *s)
{
	return (0.1);
}