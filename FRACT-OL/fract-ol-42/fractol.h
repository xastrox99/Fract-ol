/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:35:09 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/02/20 18:06:22 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<stdio.h>
# include<mlx.h>
# include<math.h>
# include<stdlib.h>
# include<unistd.h>

# define Y 800
# define X 800

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_display {
	void	*mlx;
	void	*win;
	int		max_iter;
	int		it;
	double	x_centrage;
	double	y_centrage;
	double	x_zoom;
	double	y_zoom;
	double	ci;
	double	cr;
	int		pos;
	int		fract;
	t_data	*img;
}	t_display;

typedef struct s_complex {
	double	img;
	double	real;
}	t_complex;

void	ft_putstr(char *s);
void	julia(void);
int		julia_iteration(double x, double y, t_display *vars);
int		check_pixel_color_julia(int start_x, int start_y, t_display *vars);	

void	mandelbrot(void);
int		mandelbrot_iteration(double x, double y, t_display *vars);
int		check_pixel_color_mandelbrot(int start_x, int start_y, t_display *vars);

void	burning_ship(void);
int		check_pixel_color_ship(int start_x, int start_y, t_display *vars);

char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		mouse_events(int keycode, int x, int y, t_display *vars);
int		mouse_cord(int x, int y, t_display *vars);
int		key_events(int keycode, t_display *vars);
int		hundle_no_event(t_display *vars);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif