#include "fractal.h"
void    build_mandelbrot(t_fract *fract)
{
        start_mlx(fract);
        mlx_mouse_hook(fract->win, zoom, fract);
        draw_mandelbrot(fract);
        mlx_key_hook(fract->win,key_hook, fract);
        mlx_hook(fract->win,17, 1L >> 17, cleanup, fract);
}
void    build_julia(t_fract *fract)
{
        start_mlx(fract);
        mlx_mouse_hook(fract->win, zoom_julia, fract);
        draw_julia(fract);
        mlx_key_hook(fract->win,key_hook, fract);
        mlx_hook(fract->win,17, 1L >> 17, cleanup, fract);
}