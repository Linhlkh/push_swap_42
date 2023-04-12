/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:58:43 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:04:51 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_count_move(t_stack **b, int i)
{
	int	move;
	int	size;

	size = size_stack(*b);
	if (i > size / 2)
		move = size - i;
	else
		move = -i;
	return (move);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_total_move(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}

int	get_max_index(t_stack *a)
{
	int	i;
	int	j;

	i = a->number;
	j = a->index;
	while (a)
	{
		if (i < a->number)
		{
			i = a->number;
			j = a->index;
		}
		a = a->next;
	}
	return (j);
}

int	get_number_from_i(t_stack *a, int i)
{
	while (a)
	{
		if (a->index == i)
			return (a->number);
		a = a->next;
	}
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	t_stack	*a;
// 	int	i;

// 	i = 0;
// 	a = ft_parsing(argc, argv, a);
// 	printf("index max: %i\n", get_max_index(a));
// 	printf("sup: %i", get_sup(a, 25));
// 	// while (i < size_stack(a))
// 	// {
// 	// 	printf("move: %i\n", ft_count_move(&a, i));
// 	// 	//printf("index: %i\n", i);
// 	// 	i++;
// 	// }
// }