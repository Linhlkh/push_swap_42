/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:14:54 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:05:06 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

long long int	ft_atoi(char *str)
{
	int				i;
	int				k;
	long long int	h;

	i = 0;
	k = 1;
	h = 0;
	if (!str)
		return (2);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		k = k * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		h = h * 10 + str[i] - '0';
		i++;
	}
	h = h * k;
	return (h);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main(int argc, char *argv[])
// {
// 	int i;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		printf("atoi: %i\n", ft_atoi(argv[i]));
// 		i++;
// 	}
// }