/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 02:36:05 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:39:31 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	all_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*sort_2(t_stack *a)
{
	ft_swap(&a, 'a');
	return (a);
}

t_stack	*sort_3(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->number;
	n2 = a->next->number;
	n3 = a->next->next->number;
	if (n1 < n2 && n3 < n2)
	{
		ft_re_rotate(&a, 'a', 0);
		if (!all_sorted(&a))
			ft_swap(&a, 'a');
	}
	else if (n2 < n1 && n1 < n3 && n2 < n3)
		ft_swap(&a, 'a');
	else if (n2 < n3 && n3 < n1 && n2 < n1)
		ft_rotate(&a, 'a', 0);
	else if (n3 < n2 && n2 < n1 && n3 < n1)
	{
		ft_swap(&a, 'a');
		ft_re_rotate(&a, 'a', 0);
	}
	return (a);
}

t_stack	*sort_5(t_stack *a, t_stack *b)
{
	a = ft_pushmin(a);
	ft_push(&a, &b, 'b');
	a = ft_pushmin(a);
	ft_push(&a, &b, 'b');
	a = sort_3(a);
	ft_push(&b, &a, 'a');
	ft_push(&b, &a, 'a');
	return (a);
}

void	init_idex_all(t_stack **a, t_stack **b)
{
	init_index(*a);
	init_index(*b);
}

// int main(int argc, char *argv[])
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	b = NULL;
// 	a = ft_parsing(argc, argv, a);
// 	a = sort_5(a, b);
// 	while (a)
// 	{
// 		printf("num: %i\n", a->number);
// 		a = a->next;
// 	}
// }