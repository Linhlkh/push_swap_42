/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 05:27:46 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:54:37 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_all_b(t_stack **a, t_stack **b)
{
	while (size_stack(*a) > 3)
		ft_push(a, b, 'b');
	(*a) = sort_3(*a);
	init_index(*a);
	init_index(*b);
}

int	get_sup(t_stack *a, int number)
{
	int		max;
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = get_max_index(tmp);
	max = get_number_from_i(tmp, i);
	if (number > max)
		return (get_index_min(tmp));
	while (tmp)
	{
		if (number < tmp->number && tmp->number < max)
		{
			max = tmp->number;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	return (i);
}

void	ft_move(t_stack **a, t_stack **b, int movea, int moveb)
{
	while (movea > 0)
	{
		if (moveb > 0)
			ft_rrr(a, b, moveb--);
		else
			ft_re_rotate(a, 'a', movea);
		movea--;
	}
	while (moveb > 0)
		ft_re_rotate(b, 'b', moveb--);
	while (movea < 0)
	{
		if (moveb < 0)
			ft_rr(a, b, moveb++);
		else
			ft_rotate(a, 'a', movea);
		movea++;
	}
	while (moveb < 0)
		ft_rotate(b, 'b', moveb++);
	ft_push(b, a, 'a');
	init_index(*a);
	init_index(*b);
}

void	init_move(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp_b;
	int		index;

	i = 0;
	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->move_b = ft_count_move(&b, i);
		index = get_sup(a, tmp_b->number);
		tmp_b->move_a = ft_count_move(&a, index);
		tmp_b->move_total = ft_total_move(tmp_b->move_a, tmp_b->move_b);
		tmp_b = tmp_b->next;
		i++;
	}
}

void	ft_move_all(t_stack **a, t_stack **b)
{
	int		min;
	int		movea;
	int		moveb;
	t_stack	*tmp;

	while (size_stack(*b) != 0)
	{
		min = 2147483647;
		init_idex_all(a, b);
		init_move(*a, *b);
		tmp = *b;
		while (tmp)
		{
			if (tmp->move_total < min)
			{
				min = tmp->move_total;
				movea = tmp->move_a;
				moveb = tmp->move_b;
			}
			tmp = tmp->next;
		}
		init_idex_all(a, b);
		ft_move(a, b, movea, moveb);
	}
}

// int main(int argc, char *argv[]) //test for push_all_b
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	a = ft_parsing(argc, argv, a);
// 	printf("size:%i\n", size_stack(a));
// 	push_all_b(&a, &b);
// 	printf("ec:%i\n", size_stack(b));
// 	while ((a))
// 	{
// 		printf("number:%i\n", a->number);
// 		printf("index:%i\n", a->index);
// 		a = a->next;
// 	}

// 	while ((b))
// 	{
// 		printf("number b:%i\n", b->number);
// 		printf("index b:%i\n", b->index);
// 		b = b->next;
// 	}
// }
// void	print_pile(t_stack *a, t_stack *b)
// {
// 	t_stack *tmp_a = a;
// 	t_stack *tmp_b = b;

// 	while (tmp_a)
// 	{
// 		printf("[%i]%i\n", tmp_a->index, tmp_a->number);
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("PILE A\n");
// 	printf("**************\n");
// 	while (tmp_b)
// 	{
// 		printf("[%i]%i\n", tmp_b->index, tmp_b->number);
// 		tmp_b = tmp_b->next;
// 	}
// 	printf("PILE B\n");
// }