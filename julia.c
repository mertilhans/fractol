#include "fractal.h"

int     iterate_julia(t_fract *fract, int x, int y)
{
        double c_re;
        double c_im;
        double z_re;
        double z_im;
        double temp;
        int iter;
        c_re = fract->min_re + (fract->max_re - fract->min_re) * x / WIDTH;
        c_im = fract->min_im + (fract->max_im - fract->min_im) * y / HEIGHT;
        z_re = c_re;
        z_im = c_im;
        iter = 0;

        while(z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER)
        {
                temp = z_re * z_re - z_im * z_im + fract->re;
                z_im = 2 * z_re * z_im + fract->im;
                z_re = temp;
                iter++;
        }
        return(iter);
}

void draw_julia(t_fract *fract)
{
    int x;
    int y;
    int iter;
    int color;

    x = 0;
    y = 0;
    iter = 0;

    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            iter = iterate_julia(fract, x, y);
            if (iter == MAX_ITER)
                color = 0x000000; 
            else
                color = 0x010101 * (iter % 256) + 0xFF0000 * (iter % 128);
            put_pixel(fract, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
int zoom_julia(int button, int x, int y, t_fract *fract)
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
    draw_julia(fract);
    return (0);
}