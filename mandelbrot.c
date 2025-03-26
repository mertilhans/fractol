#include "fractol.h"
void put_pixel(t_fract *fract, int x, int y, int color)
{
    int index;
    index = y * WIDTH + x;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        fract->img_data[index] = color;
    else
        handle_errors("İnvalid pixel x / y");
}

int     iterate_mandelbrot(t_fract *fract, int x, int y)
{
    double temp;
    int iter;

    fract->c_re = fract->min_re + (fract->max_re - fract->min_re) * x
           / (double)WIDTH;
    fract->c_im = fract->min_im + (fract->max_im - fract->min_im) * y
           / (double)HEIGHT;
    fract->z_re = fract->c_re;
    fract->z_im = fract->c_im;
    iter = 0;

    while (fract->z_re * fract->z_re + fract->z_im * fract->z_im <= 4 && iter < MAX_ITER)
    {
        temp = fract->z_re * fract->z_re - fract->z_im * fract->z_im + fract->c_re;
        fract->z_im = 2 * fract->z_re * fract->z_im + fract->c_im;
        fract->z_re = temp;
        iter++;
    }
    return (iter);
}
void draw_mandelbrot(t_fract *fract)
{
    int x;
    int y;
    int iter;
    int color;

    x = 0;
    y = 0;
    iter = 0;
    color = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            iter = iterate_mandelbrot(fract, x, y);
            if (iter == MAX_ITER)
                color = 0x000000;
            else
                color = (iter * 0x010101) % 0xFFFFFF;
            put_pixel(fract, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
int zoom(int button, int x, int y, t_fract *fract)
{
    double factor;
    double mouse_re;
    double mouse_im;

    mouse_re = fract->min_re + (fract->max_re - fract->min_re) * x / (double)WIDTH;
    mouse_im = fract->min_im + (fract->max_im - fract->min_im) * y / (double)HEIGHT;

    if (button == 4)  
        factor = 0.9; 
    else if (button == 5)
        factor = 1.1; 
    else
        return (0);

    fract->min_re = mouse_re + (fract->min_re - mouse_re) * factor;
    fract->max_re = mouse_re + (fract->max_re - mouse_re) * factor;
    fract->min_im = mouse_im + (fract->min_im - mouse_im) * factor;
    fract->max_im = mouse_im + (fract->max_im - mouse_im) * factor;

    fract->zoom *= factor;
    draw_mandelbrot(fract);
    return (0);
}