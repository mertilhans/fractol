#include "fractal.h"
void    start_mlx(t_fract *fract)
{
        fract->mlx = mlx_init();
        if (!fract)
            cleanup(fract);
        if (!fract->mlx)
        {
                ft_putstr("Failed to init");
                cleanup (fract);
        }
        fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "FRACTAL");
        if(!fract->win)
        {
                ft_putstr("Failed to create window");
                cleanup(fract);
        }
        fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
        if(!fract->img)
        {
                ft_putstr("Failed to create new image");
                cleanup(fract);
        }
        fract->img_data = (int*)mlx_get_data_addr(fract->img, &fract->bpp, &fract->size_line, &fract->endian);
        start_point(fract);
}
int cleanup(t_fract *fract)
{
    if (fract->img)
        mlx_destroy_image(fract->mlx,fract->img);
    if (fract->win)
        mlx_destroy_window(fract->mlx, fract->win);
    if (fract->mlx)
    {
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
    }
    if (fract)
        free(fract);
    exit(0);
}
int key_hook(int keycode, t_fract *fract)
{
    if (keycode == ESCAPE)  
        handle_errors("ESC\n",fract);
    return 0;
}
void start_point(t_fract *fract)
{
    fract->min_re = -2.0;
    fract->max_re = 1.5;
    fract->min_im = -1.5;
    fract->max_im = 1.5;
}