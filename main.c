#include "fractal.h"
int main(int ac,char **av)
{
        t_fract *fract;

        fract = malloc(sizeof(t_fract));
        if(ac == 2 && ft_strcmp(av[1], "Mandelbrot") == 0)
                build_mandelbrot(fract);
        else if(ac == 2 && ft_strcmp(av[1], "Julia") == 0)
                handle_errors("usage :Julia <value> <value>\n"
                              "Julia set 1 : <-0.70176>  <0.3842> \n"
                              "Julia set 2 : <-0.8> <0.156> \n "
                              "Julia set 3 : <0.285> <0.01> \n"
                              "Julia set 4: <0.355> <0.355>\n"
                              "Julia set 5 : <-0.7> <0.27015>\n" ,fract);
        else if(ac == 4 && ft_strcmp(av[1], "Julia") == 0)
        {
                fract->re = ft_atod(av[2],fract);
                fract->im = ft_atod(av[3],fract);
                build_julia(fract);
        }
        else
                handle_errors("Usage : Mandelbrot or Julia <value> <value>  RTFM!!!!!!!\n",fract);
        mlx_loop(fract->mlx);
        return 0;
}



