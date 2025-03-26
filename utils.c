/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:38:01 by merilhan          #+#    #+#             */
/*   Updated: 2025/03/26 16:43:58 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 == *s2) && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	is_neg = 1;
	nb = 0;
	div = 0.1;
	i = ft_skip(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
		nb = (nb * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb += (str[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		handle_errors("İnvalied,Error\n");
	return (nb * is_neg);
}
