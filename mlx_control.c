/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:59 by merilhan          #+#    #+#             */
/*   Updated: 2025/03/26 16:43:24 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
	{
		ft_putstr("Failed to init");
		cleanup(fract);
	}
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "FRACTOL");
	if (!fract->win)
	{
		ft_putstr("Failed to create window");
		cleanup(fract);
	}
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img)
	{
		ft_putstr("Failed to create new image");
		cleanup(fract);
	}
}

int	cleanup(t_fract *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	exit(0);
}

int	key_hook_mandelbrot(int keycode, t_fract *fract)
{
	if (keycode == ESCAPE)
		cleanup(fract);
	if (keycode == W || keycode == UP)
	{
		fract->min_im -= 0.015;
		fract->max_im -= 0.015;
	}
	if (keycode == S || keycode == DOWN)
	{
		fract->max_im += 0.015;
		fract->min_im += 0.015;
	}
	if (keycode == A || keycode == LEFT)
	{
		fract->max_re -= 0.015;
		fract->min_re -= 0.015;
	}
	if (keycode == D || keycode == RIGHT)
	{
		fract->max_re += 0.015;
		fract->min_re += 0.015;
	}
	draw_mandelbrot(fract);
	return (0);
}

int	key_hook_julia(int keycode, t_fract *fract)
{
	if (keycode == ESCAPE)
		cleanup(fract);
	if (keycode == W || keycode == UP)
	{
		fract->min_im -= 0.015;
		fract->max_im -= 0.015;
	}
	if (keycode == S || keycode == DOWN)
	{
		fract->max_im += 0.015;
		fract->min_im += 0.015;
	}
	if (keycode == A || keycode == LEFT)
	{
		fract->max_re -= 0.015;
		fract->min_re -= 0.015;
	}
	if (keycode == D || keycode == RIGHT)
	{
		fract->max_re += 0.015;
		fract->min_re += 0.015;
	}
	draw_julia(fract);
	return (0);
}

void	start_point(t_fract *fract)
{
	fract->img_data = (int *)mlx_get_data_addr(fract->img, &fract->bpp,
			&fract->size_line, &fract->endian);
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -1.0;
	fract->max_im = 1.5;
}
