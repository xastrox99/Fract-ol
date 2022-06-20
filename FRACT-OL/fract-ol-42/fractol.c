/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:08:50 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 17:59:58 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*fract_init(void)
{
	t_display	*vars;

	vars = malloc(sizeof(t_display));
	if (!vars)
		return (NULL);
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
	{
		free(vars);
		return (NULL);
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, X, Y, "Hello world!");
	vars->img->img = mlx_new_image(vars->mlx, X, Y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
	return (vars);
}

void	julia(void)
{
	t_display	*vars;

	vars = fract_init();
	vars->x_zoom = 4.0 / X;
	vars->y_zoom = 4.0 / Y;
	vars->x_centrage = 2.0;
	vars->y_centrage = 2.0;
	vars->max_iter = 50;
	vars->pos = 1;
	vars->fract = 2;
	mlx_hook(vars->win, 4, 0, mouse_events, vars);
	mlx_hook(vars->win, 6, 0, mouse_cord, vars);
	mlx_hook(vars->win, 2, 0, key_events, vars);
	mlx_loop_hook(vars->mlx, hundle_no_event, vars);
	mlx_loop(vars->mlx);
}

void	mandelbrot(void)
{
	t_display	*vars;

	vars = fract_init();
	vars->x_zoom = 4.0 / X;
	vars->y_zoom = 4.0 / Y;
	vars->x_centrage = 2.0;
	vars->y_centrage = 2.0;
	vars->max_iter = 50;
	vars->fract = 1;
	mlx_hook(vars->win, 4, 0, mouse_events, vars);
	mlx_hook(vars->win, 2, 0, key_events, vars);
	mlx_loop_hook(vars->mlx, hundle_no_event, vars);
	mlx_loop(vars->mlx);
}

void	burning_ship(void)
{
	t_display	*vars;

	vars = fract_init();
	vars->x_zoom = 4.0 / X;
	vars->y_zoom = 4.0 / Y;
	vars->x_centrage = 2.0;
	vars->y_centrage = 2.0;
	vars->max_iter = 50;
	vars->fract = 3;
	mlx_hook(vars->win, 4, 0, mouse_events, vars);
	mlx_hook(vars->win, 2, 0, key_events, vars);
	mlx_loop_hook(vars->mlx, hundle_no_event, vars);
	mlx_loop(vars->mlx);
}
