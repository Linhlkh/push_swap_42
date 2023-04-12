/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sujet1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 06:31:56 by khle              #+#    #+#             */
/*   Updated: 2023/04/08 19:05:15 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (!(*stack))
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp3 = (*stack)->next->next;
	*stack = tmp2;
	(*stack)->next = tmp1;
	tmp1->next = tmp3;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_push(t_stack **stack1, t_stack **stack2, char c)
{
	t_stack	*tmp;

	if (stack1 == NULL)
		return ;
	tmp = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = tmp;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	ft_rotate(t_stack **a, char c, int x)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	(void)x;
	if (!(*a))
		return ;
	tmp1 = *a;
	tmp2 = *a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	*a = (*a)->next;
	tmp1->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_re_rotate(t_stack **a, char c, int x)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	(void)x;
	if (!(*a))
		return ;
	tmp1 = (*a);
	while ((*a)->next != NULL)
	{
		tmp2 = *a;
		*a = (*a)->next;
	}
	(*a)->next = tmp1;
	tmp2->next = NULL;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

// int main()
// {
// 	t_stack *a;
// 	a = (t_stack *)malloc(sizeof(t_stack));
// 	(a)->number = 12;
// 	(a)->next =(t_stack *) malloc(sizeof(t_stack));
// 	(a)->next->number = 24;
// 	(a)->next->next = (t_stack *)malloc(sizeof(t_stack));
// 	(a)->next->next->number = 36;

// 	// t_stack *b;
// 	// b = (t_stack *)malloc(sizeof(t_stack));
// 	// (b)->number = 3;
// 	// (b)->next =(t_stack *) malloc(sizeof(t_stack));
// 	// (b)->next->number = 5;
// 	// (b)->next->next = (t_stack *)malloc(sizeof(t_stack));
// 	// (b)->next->next->number = 7;

// 	ft_re_rotate(&a, 'a');
// 	printf("num node 1a:%i\n", (a)->number);
// 	//printf("num node 1b:%i\n", (a)->next->number);
// 	printf("num node 2a:%i\n", (a)->next->number);
// 	//printf("num node 2b:%i\n", (b)->next->number);
// 	printf("num node 3a:%i\n", (a)->next->next->number);
// 	if ((a)->next->next->next == NULL)
// 		printf("NULL");
// }