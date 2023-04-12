/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:07:07 by khle              #+#    #+#             */
/*   Updated: 2023/04/08 23:53:27 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_newlst(int num)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->next = NULL;
	a->number = num;
	a->index = 0;
	a->move_total = 0;
	a->move_a = 0;
	a->move_b = 0;
	return (a);
}

t_stack	*ft_addlast(t_stack *a, t_stack *new)
{
	t_stack	*tmp;

	tmp = a;
	if (!new)
		return (NULL);
	if (!(a))
		a = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (a);
}

void	init_index(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	size_stack(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// int main()
// {
// 	t_stack *a;
// 	t_stack	*b;

// 	//a = malloc(sizeof(t_stack *));
// 	//a = malloc(sizeof(t_stack));
// 	a = NULL;
// 	printf("here\n");
// 	// (a)->next = NULL;
// 	// (a)->number = 15;
// 	printf("here\n");
// 	b = ft_newlst(35);
// 	a = ft_addlast(a, b);
// 	printf("a.num: %i\n", (a)->number);
// 	printf("a.nextnum: %i\n", (a)->next->number);
// }