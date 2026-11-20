/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulja <zabdulja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:29:29 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:26:23 by zabdulja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct stack
{
	int				value;
	struct stack	*next;
	int				index;
}					t_stack;

//===========filling and checking args=======================================
void				push_swap(char **integers, int av, t_stack **a);
void				push_stack(t_stack **lst, t_stack *new);

int					fill_stack(char **args, t_stack **a, int av,
						int selector_flag);

t_stack				*create_node(int value);

/////////////modified libft//////////////////////////////
int					parse_integer(char **npt, t_stack *a, int j);
long				parse_digits(char *nptr, int *i);
char				**free_string_array(char **strs);
char				**merge_string_arrays(char **splitted, char **integers);
t_stack				*stack_last(t_stack *lst);
void				stack_add_front(t_stack **lst, t_stack *new,
						char **integers);
//=================operations=============================================
int					swap_a(t_stack **a, int *ops_count);
int					swap_b(t_stack **b, int *ops_count);
int					push_a(t_stack **a, t_stack **b, int *ops_count);
int					push_b(t_stack **a, t_stack **b, int *ops_count);
int					rotate_a(t_stack **a, int *ops_count);
int					rotate_b(t_stack **a, int *ops_count);
int					has_less_than_two(t_stack *a);
int					reverse_rotate_a(t_stack **a, int *ops_count);
int					reverse_rotate_a(t_stack **a, int *ops_count);
int					reverse_rotate_b(t_stack **a, int *ops_count);
int					ss(t_stack **a, t_stack **b, int *ops_count);
int					rr(t_stack **a, t_stack **b, int *ops_count);
int					rrr(t_stack **a, t_stack **b, int *ops_count);
//======================sorting===========================================
void				sort_simple(t_stack **a, int size, int bench_flag);
void				sort_complex(t_stack **a, int size, int bench_flag);
void				sort_medium(t_stack **a, int size, int bench_flag);
void				sort_adaptive(t_stack **a, int size, int bench_flag);
void				finish_sort(int *ops_count, int disorder, int bench_flag,
						char *strategy);
void				rotate_to_top(t_stack **s, char c, int pos, int *ops);
void				rotate_to_top_simple(t_stack **s, int pos, int *ops);
void				assign_ranks(t_stack **a);
void				sort_three(t_stack **a, int *ops_count, int disorder);
//=======================extra===========================================
double				compute_disorder(t_stack *a);
void				print_benchmark(int *ops_count, int disorder, char *strategy);
void				print_error(void);
void				init_op_counts(int **ops_count);
void				free_nodes(t_stack *a);
int					stack_size(t_stack *a);
int					count_strings(char **strs);
//=================bouns==================================================
int					swap_b_bonus(t_stack **b);
int					swap_a_bonus(t_stack **a);
int					ss_bonus(t_stack **a, t_stack **b);
int					push_a_bonus(t_stack **a, t_stack **b);
int					push_b_bonus(t_stack **a, t_stack **b);
int					rotate_bonus(t_stack **a);
int					reverse_rotate_bonus(t_stack **a);
int					rr_bonus(t_stack **a, t_stack **b);
int					rrr_bonus(t_stack **a, t_stack **b);

#endif
