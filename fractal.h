#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 400
# define HEIGHT 400
# define MAX_ITER 350
# define ESCAPE 65307

typedef struct s_fract
{
    void    *mlx;
    void    *win;
    void    *img;
    int     *img_data;
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    double  re;
    double  im;
    int     bpp;           // bits per pixel
    int     size_line;     // line size in bytes
    int     endian;
}               t_fract;

int cleanup(t_fract *fract);
int key_hook(int keycode, t_fract *fract);
int ft_strcmp(const char *s1, const char *s2);
void    ft_putstr(const char *str);
int     iterate_mandelbrot(t_fract *fract, int x, int y);
int     iterate_julia(t_fract *fract, int x, int y);
void    put_pixel(t_fract *fract, int x,int y, int color);
void draw_mandelbrot(t_fract *fract);
void draw_julia(t_fract *fract);
void    start_mlx(t_fract *run);
void    build_mandelbrot(t_fract *run);
int zoom(int button, int x, int y, t_fract *fract);
void    build_julia(t_fract *fract);
void    start_point(t_fract *fract);
int     ft_isdigit(int c);
int ft_skip(char *str,int *sign);
double	ft_atod(char *str, t_fract *fract);
void    handle_errors(const char *error_type,t_fract *fract);
void	*ft_memset(void *s, int c, size_t len);
int zoom_julia(int button, int x, int y, t_fract *fract);

#endif

