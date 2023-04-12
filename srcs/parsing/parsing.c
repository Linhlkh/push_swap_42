/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:33:51 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:05:48 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_min_max(char *argv)
{
	long int	i;

	if (!argv || !*argv)
		return (0);
	i = ft_atoi(argv);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

int	check_valid_digit(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*ft_parsing(int argc, char *argv[], t_stack *a)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		if (!check_min_max(argv[i]) || !check_valid_digit(argv[i]))
			ft_error(a, NULL);
		i++;
	}
	if (!check_duplicate(argc, argv))
		ft_error(a, NULL);
	i = 1;
	while (i < argc)
	{
		new = ft_newlst(ft_atoi(argv[i]));
		a = ft_addlast(a, new);
		i++;
	}
	if (!a)
		ft_error(a, NULL);
	init_index(a);
	return (a);
}

// int main(int argc, char *argv[])
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	printf("argc:%i\n", argc);

// 	a = ft_parsing(argc, argv, a);
// 	printf("size:%i\n", size_stack(a));
// 	//printf("index min:%i\n", get_index_min(a));
// 	//ft_rotate(&a, 'a');
// 	//a = ft_pushmin(a);
// 	printf("size after pushmin:%i\n", size_stack(a));
// 	printf("index min after pushmin:%i\n", get_index_min(a));
// 	while ((a))
// 	{
// 		printf("number:%i\n", a->number);
// 		//printf("index:%i\n", a->index);
// 		a = a->next;
// 	}
// }
// int main(int argc, char **argv)
// {
// 	int i;
// 	i = 1;

// 	while (i < argc)
// 	{
// 		printf("minmax: %i\n", check_min_max(argv[i]));
// 		printf("digit:%i\n", check_valid_digit(argv[i]));
// 		i++;
// 	}
// 	printf("argc:%i\n", argc);
// 	//char* new[] = {"fc454", "7454", "548", "7454", NULL};
// 	printf("%i", check_duplicate(argc, argv));
// }