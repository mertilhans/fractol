#include "fractal.h"

void  handle_errors(const char *error_type,t_fract *fract)
{
        if(error_type)
                ft_putstr(error_type);
        cleanup(fract);
}
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (s);
}
