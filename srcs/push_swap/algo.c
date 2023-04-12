/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:44:18 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 05:59:30 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	**rotate_min(t_stack **a, char c)
{
	int	size;

	size = size_stack(*a);
	if (get_index_min(*a) > size / 2)
	{
		while (get_index_min(*a) != 0)
		{
			ft_re_rotate(a, c, 0);
			init_index(*a);
		}
	}
	else
	{
		while (get_index_min(*a) != 0)
		{
			ft_rotate(a, c, 0);
			init_index(*a);
		}
	}
	return (a);
}

void	algo_big(t_stack **a, t_stack **b)
{
	push_all_b(a, b);
	ft_move_all(a, b);
	rotate_min(a, 'a');
}

void	ft_algo(t_stack **a, t_stack **b)
{
	if (all_sorted(a) == 1)
		;
	else if (size_stack(*a) == 2)
		*a = sort_2(*a);
	else if (size_stack(*a) == 3)
		*a = sort_3(*a);
	else if (size_stack(*a) == 5)
		*a = sort_5(*a, *b);
	else
		algo_big(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = NULL;
	a = ft_parsing(argc, argv, a);
	b = NULL;
	ft_algo(&a, &b);
	ft_free(a, b);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	b = NULL;
// 	a = ft_parsing(argc, argv, a);
// 	// printf("size:%i\n", size_stack(a));
// 	ft_algo(&a, &b);
// 	// printf("size b: %i\n", size_stack(b));
// 	// printf("size a: %i\n", size_stack(a));
// 	while (a)
// 	{
// 		printf("number: %i\n", a->number);
// 		a = a->next;
// 	}
// }
