/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:34 by merilhan          #+#    #+#             */
/*   Updated: 2025/03/26 16:38:12 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	build_mandelbrot(t_fract *fract)
{
	start_mlx(fract);
	start_point(fract);
	mlx_mouse_hook(fract->win, zoom, fract);
	draw_mandelbrot(fract);
	mlx_key_hook(fract->win, key_hook_mandelbrot, fract);
	mlx_hook(fract->win, 17, 0, cleanup, fract);
	mlx_loop(fract->mlx);
}

void	build_julia(t_fract *fract)
{
	start_mlx(fract);
	start_point(fract);
	mlx_mouse_hook(fract->win, zoom_julia, fract);
	draw_julia(fract);
	mlx_key_hook(fract->win, key_hook_julia, fract);
	mlx_hook(fract->win, 17, 0, cleanup, fract);
	mlx_loop(fract->mlx);
}
