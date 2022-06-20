/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:35:09 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 18:02:42 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
			mandelbrot();
		else if (ft_strncmp(av[1], "julia", 5) == 0)
			julia();
		else if (ft_strncmp(av[1], "burning ship", 12) == 0)
			burning_ship();
		else
			ft_putstr("tarayat a zbi");
	}
	return (0);
}
