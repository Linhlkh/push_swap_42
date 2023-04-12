/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 06:33:29 by khle              #+#    #+#             */
/*   Updated: 2023/04/09 06:55:04 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	int				index;
	int				move_total;
	int				move_a;
	int				move_b;
}				t_stack;

// utils //
int					ft_strlen(char *c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
long long int		ft_atoi(char *str);
int					ft_isdigit(int c);

// utils_sujet //

void				ft_swap(t_stack **stack, char c);
void				ft_push(t_stack **stack1, t_stack **stack2, char c);
void				ft_rotate(t_stack **a, char c, int x);
void				ft_re_rotate(t_stack **a, char c, int x);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_rr(t_stack **a, t_stack **b, int x);
void				ft_rrr(t_stack **a, t_stack **b, int x);
int					get_index_min(t_stack *a);
t_stack				*ft_pushmin(t_stack *a);

// utils_lst //

t_stack				*ft_newlst(int num);
t_stack				*ft_addlast(t_stack *a, t_stack *new);
void				init_index(t_stack *a);
int					size_stack(t_stack *a);

// utils_sort //

int					ft_count_move(t_stack **b, int i);
int					ft_abs(int i);
int					ft_total_move(int a, int b);
int					get_max_index(t_stack *a);
int					get_number_from_i(t_stack *a, int i);

// parsing //

void				ft_free(t_stack *a, t_stack *b);
void				ft_error(t_stack *a, t_stack *b);
int					check_min_max(char *argv);
int					check_valid_digit(char *argv);
int					check_duplicate(int argc, char *argv[]);
t_stack				*ft_parsing(int argc, char *argv[], t_stack *a);

// sort //

int					all_sorted(t_stack **a);
t_stack				*sort_2(t_stack *a);
t_stack				*sort_3(t_stack *a);
t_stack				*sort_5(t_stack *a, t_stack *b);
void				push_all_b(t_stack **a, t_stack **b);
int					get_sup(t_stack *a, int number);
void				ft_move(t_stack **a, t_stack **b, int movea, int moveb);
void				init_move(t_stack *a, t_stack *b);
void				ft_move_all(t_stack **a, t_stack **b);
t_stack				**rotate_min(t_stack **a, char c);
void				algo_big(t_stack **a, t_stack **b);
void				ft_algo(t_stack **a, t_stack **b);
void				init_idex_all(t_stack **a, t_stack **b);

#endif