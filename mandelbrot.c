#include "fractal.h"
void put_pixel(t_fract *fract, int x, int y, int color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        fract->img_data[y * WIDTH + x] = color;
}
int     iterate_mandelbrot(t_fract *fract, int x, int y)
{
    double c_re;
    double c_im;
    double z_re;
    double z_im;
    double temp;
    int iter;

    c_re = fract->min_re + (fract->max_re - fract->min_re) * x
           / (double)WIDTH;
    c_im = fract->min_im + (fract->max_im - fract->min_im) * y
           / (double)HEIGHT;
    z_re = c_re;
    z_im = c_im;
    iter = 0;

    while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER)
    {
        temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        iter++;
    }
    return (iter);
}
void draw_mandelbrot(t_fract *fract)
{
    int x = 0;
    int y = 0;
    int iter = 0;
    int color = 0;

    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            iter = iterate_mandelbrot(fract, x, y);
            if (iter == MAX_ITER)
                color = 0x000000; // Siyah renk (Fraktal dışı)
            else
                color = iter * 255 / MAX_ITER; // Renk yoğunluğu
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
    draw_mandelbrot(fract);
    return (0);
}