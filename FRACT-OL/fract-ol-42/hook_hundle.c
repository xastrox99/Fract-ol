/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_hundle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:42:56 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 18:00:33 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_cord(int x, int y, t_display *vars)
{
	if (vars->pos > 0)
	{
		vars->cr = ((x * vars->x_zoom) - vars->x_centrage);
		vars->ci = ((y * vars->y_zoom) - vars->y_centrage);
	}
	return (0);
}

int	mouse_events(int keycode, int x, int y, t_display *vars)
{
	if (keycode == 5)
	{
		vars->max_iter += 20;
		vars->x_zoom *= 0.5;
		vars->y_zoom *= 0.5;
		vars->x_centrage = vars->x_centrage - (x * vars->x_zoom);
		vars->y_centrage = vars->y_centrage - (y * vars->y_zoom);
	}
	else if (keycode == 4)
	{
		vars->max_iter -= 20;
		vars->x_centrage = vars->x_centrage + (x * vars->x_zoom);
		vars->y_centrage = vars->y_centrage + (y * vars->y_zoom);
		vars->x_zoom /= 0.5;
		vars->y_zoom /= 0.5;
	}
	else if (keycode == 1)
		vars->pos *= -1;
	return (0);
}

int	key_events(int keycode, t_display *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->img);
		free(vars);
		exit(0);
	}
	else if (keycode == 124)
		vars->x_centrage /= 1.01;
	else if (keycode == 123)
		vars->x_centrage *= 1.01;
	else if (keycode == 125)
		vars->y_centrage /= 1.01;
	else if (keycode == 126)
		vars->y_centrage *= 1.01;
	return (0);
}

int	hundle_no_event(t_display *vars)
{
	if (vars->fract == 1)
		check_pixel_color_mandelbrot(0, 0, vars);
	else if (vars->fract == 2)
		check_pixel_color_julia(0, 0, vars);
	else if (vars->fract == 3)
		check_pixel_color_ship(0, 0, vars);
	return (1);
}
