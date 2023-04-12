/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sujet2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 02:30:25 by khle              #+#    #+#             */
/*   Updated: 2023/04/08 23:59:30 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, '0');
	ft_swap(b, '0');
	ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, int x)
{
	(void)x;
	ft_rotate(a, '0', x);
	ft_rotate(b, '0', x);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, int x)
{
	(void)x;
	ft_re_rotate(a, '0', x);
	ft_re_rotate(b, '0', x);
	ft_putstr_fd("rrr\n", 1);
}

int	get_index_min(t_stack *a)
{
	int	i;
	int	j;

	i = a->number;
	j = a->index;
	while (a)
	{
		if (i > a->number)
		{
			i = a->number;
			j = a->index;
		}
		a = a->next;
	}
	return (j);
}

t_stack	*ft_pushmin(t_stack *a)
{
	if (get_index_min(a) > size_stack(a) / 2)
	{
		while (get_index_min(a) != 0)
		{
			ft_re_rotate(&a, 'a', 0);
			init_index(a);
		}
	}
	else
	{
		while (get_index_min(a) != 0)
		{
			ft_rotate(&a, 'a', 0);
			init_index(a);
		}
	}
	return (a);
}
