/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:39 by merilhan          #+#    #+#             */
/*   Updated: 2025/03/26 17:18:15 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 250
# define ESCAPE 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define W 119
# define S 115
# define A 97
# define D 100
# define X 120

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re;
	double	im;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		bpp;
	int		size_line;
	int		endian;
}			t_fract;

int			cleanup(t_fract *fract);
int			key_hook_mandelbrot(int keycode, t_fract *fract);
int			key_hook_julia(int keycode, t_fract *fract);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(const char *str);
int			iterate_mandelbrot(t_fract *fract, int x, int y);
int			iterate_julia(t_fract *fract, int x, int y);
void		put_pixel(t_fract *fract, int x, int y, int color);
void		draw_mandelbrot(t_fract *fract);
void		draw_julia(t_fract *fract);
void		start_mlx(t_fract *run);
void		build_mandelbrot(t_fract *run);
int			zoom(int button, int x, int y, t_fract *fract);
void		build_julia(t_fract *fract);
void		start_point(t_fract *fract);
int			ft_isdigit(int c);
int			ft_skip(char *str, int *sign);
double		ft_atod(char *str);
int			handle_errors(const char *error_type);
int			zoom_julia(int button, int x, int y, t_fract *fract);

#endif
