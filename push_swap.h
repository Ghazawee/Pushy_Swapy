/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:09:01 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 17:43:41 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				a_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// split
char					**ft_split(char const *s, char c);
int						ft_wount(char *s, char c);

// free & errors
int						errors(char *s);
int						only_space(char *s);
int						duperr(t_stack_node *s, int n);
void					frees(t_stack_node **s);
void					ft_error(t_stack_node **s, char **arr, char *str,
							int len);

// initialization
void					addnode(t_stack_node **s, int n);
t_stack_node			*flastn(t_stack_node *s);
void					inzsa(t_stack_node **s, char **av, char *str, int len);
t_stack_node			*find_cheap_node(t_stack_node *s);
void					prepush(t_stack_node **s, t_stack_node *head_node,
							char wstack);

// swap
void					swap(t_stack_node **s);
void					sa(t_stack_node **a, bool tf);
void					sb(t_stack_node **b, bool tf);
void					ss(t_stack_node **a, t_stack_node **b, bool tf);

// revrotate
void					revrotate(t_stack_node **s);
void					rra(t_stack_node **a, bool tf);
void					rrb(t_stack_node **b, bool tf);
void					rrr(t_stack_node **a, t_stack_node **b, bool tf);
void					revrot_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheap);

// rotate
void					rotate(t_stack_node **s);
void					ra(t_stack_node **a, bool tf);
void					rb(t_stack_node **b, bool tf);
void					rr(t_stack_node **a, t_stack_node **b, bool tf);
void					rot_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheap);

// push
void					push(t_stack_node **d, t_stack_node **s);
void					pa(t_stack_node **a, t_stack_node **b, bool tf);
void					pb(t_stack_node **b, t_stack_node **a, bool tf);

// stacks
long					ft_atol(char *s);
bool					stack_sorted(t_stack_node *s);
void					push_cost(t_stack_node *a, t_stack_node *b);
t_stack_node			*findmin(t_stack_node *s);
t_stack_node			*findmax(t_stack_node *s);

// stack utilities
void					index_node(t_stack_node *s);
void					a_target_node(t_stack_node *a, t_stack_node *b);
void					b_target_node(t_stack_node *a, t_stack_node *b);
int						stack_len(t_stack_node *s);
void					cheapestn(t_stack_node *s);

// comove
void					it_b(t_stack_node *a, t_stack_node *b);
void					itpc_a(t_stack_node *a, t_stack_node *b);
void					push_b_a(t_stack_node **a, t_stack_node **b);
void					push_a_b(t_stack_node **a, t_stack_node **b);

// sorts
void					head_is_min(t_stack_node **a);
void					sorthree(t_stack_node **a);
void					sortwo(t_stack_node *a);
void					sort_other(t_stack_node **a, t_stack_node **b);

// strings utils
void					*ft_calloc(size_t count, size_t size);
int						ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s1);
char					*one_big_str(int ac, char **av);

// preinits
void					ft_free_arr_str(char *str, char **array, int len);
void					preinit_stack(t_stack_node **a, int ac, char **av);

#endif