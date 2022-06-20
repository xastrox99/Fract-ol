/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:30:35 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 18:03:52 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iteration(double x, double y, t_display *vars)
{
	t_complex	res;
	t_complex	c;
	t_complex	z;

	vars->it = 0;
	c.real = vars->cr;
	c.img = vars->ci;
	z.real = ((x * vars->x_zoom) - vars->x_centrage);
	z.img = ((y * vars->y_zoom) - vars->y_centrage);
	while (vars->it < vars->max_iter
		&& ((z.real * z.real) + (z.img * z.img) < 4))
	{
		res.real = ((z.real * z.real) - (z.img * z.img)) + c.real;
		res.img = 2 * z.real * z.img + c.img;
		z = res;
		vars->it++;
	}
	return (vars->it);
}

int	check_pixel_color_julia(int start_x, int start_y, t_display *vars)
{
	while (start_y < Y)
	{
		start_x = 0;
		while (start_x < X)
		{
			vars->it = julia_iteration(start_x, start_y, vars);
			if (vars->it == vars->max_iter)
				my_mlx_pixel_put(vars->img, start_x, start_y, 0xffffff);
			else
				my_mlx_pixel_put(vars->img, start_x, start_y,
					0x000000 / vars->it);
			start_x++;
		}
		start_y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
