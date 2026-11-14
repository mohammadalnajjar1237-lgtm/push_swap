/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:29:29 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 11:29:31 by moalnajj         ###   ########.fr       */
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

t_stack				*create_stack(int value);

/////////////modified libft//////////////////////////////
int					ft_atoi_m(char **npt, t_stack *a, int j);
long				turn_to_int(char *nptr, int *i);
char				**free_all(char **strs);
char				**ft_strjoin_m(char **splitted, char **integers);
t_stack				*ft_lstlast2(t_stack *lst);
void				ft_lstadd_front2(t_stack **lst, t_stack *new,
						char **integers);
//=================operations=============================================
int					swap_a(t_stack **a, int *ops_count);
int					swap_b(t_stack **b, int *ops_count);
int					push_a(t_stack **a, t_stack **b, int *ops_count);
int					push_b(t_stack **a, t_stack **b, int *ops_count);
int					rotate_a(t_stack **a, int *ops_count);
int					rotate_b(t_stack **a, int *ops_count);
int					is_empty_or_unary(t_stack *a);
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
void				sort_adaptivly(t_stack **a, int size, int bench_flag);
void				end_sort(int *ops_count, int disorder, int bench_flag,
						char *strategy);
void				rotate_to_top(t_stack **s, char c, int pos, int *ops);
void				rotate_to_top_simple(t_stack **s, int pos, int *ops);
void				index_stack(t_stack **a);
void				sort_three(t_stack **a, int *ops_count, int disorder);
//=======================extra===========================================
double				compute_disorder(t_stack *a);
void				bench(int *ops_count, int disorder, char *strategy);
void				print_error(void);
void				init_ops(int **ops_count);
void				free_nodes(t_stack *a);
int					stack_size(t_stack *a);
int					num_pointers(char **strs);
//=================bouns==================================================
int					swap_b_bouns(t_stack **b);
int					swap_a_bouns(t_stack **a);
int					ss_bouns(t_stack **a, t_stack **b);
int					push_a_bouns(t_stack **a, t_stack **b);
int					push_b_bouns(t_stack **a, t_stack **b);
int					rotate_bouns(t_stack **a);
int					reverse_rotate_bouns(t_stack **a);
int					rr_bouns(t_stack **a, t_stack **b);
int					rrr_bouns(t_stack **a, t_stack **b);

#endif
