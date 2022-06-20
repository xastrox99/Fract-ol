/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_Ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:39:36 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 18:05:25 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ship_iteration(int x, int y, t_display *vars)
{
	t_complex	r;
	t_complex	c;
	t_complex	z;

	z.real = 0.0;
	z.img = 0.0;
	vars->it = 0;
	c.real = ((x * vars->x_zoom) - vars->x_centrage);
	c.img = ((y * vars->y_zoom) - vars->y_centrage);
	while (((z.real * z.real) + (z.img * z.img) < 4)
		&& vars->it < vars->max_iter)
	{
		r.real = (fabs(z.real) * fabs(z.real)) - (fabs(z.img) * fabs(z.img));
		r.real += c.real;
		r.img = (2 * fabs(z.img) * fabs(z.real)) + c.img;
		z = r;
		vars->it++;
	}
	return (vars->it);
}

int	check_pixel_color_ship(int start_x, int start_y, t_display *vars)
{
	while (start_y < Y)
	{
		start_x = 0;
		while (start_x < X)
		{
			vars->it = ship_iteration(start_x, start_y, vars);
			if (vars->it == vars->max_iter)
				my_mlx_pixel_put(vars->img, start_x, start_y, 0xffffff);
			else
				my_mlx_pixel_put(vars->img, start_x, start_y,
					0xFFFFFF / vars->it);
			start_x++;
		}
		start_y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
