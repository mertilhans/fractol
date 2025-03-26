#include "fractol.h"

int  handle_errors(const char *error_type)
{
        if(error_type)
                ft_putstr(error_type);
        exit(1);
}

