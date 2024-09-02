/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:43 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:07:20 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *s)
{
	int	len;

	len = 0;
	while (s)
	{
		len++;
		s = s->next;
	}
	return (len);
}

void	index_node(t_stack_node *s)
{
	int	i;
	int	len;
	int	median;

	i = 0;
	if (!s)
		return ;
	len = stack_len(s);
	median = len / 2;
	while (s)
	{
		s->index = i;
		if (i <= median)
			s->a_median = true;
		else
			s->a_median = false;
		s = s->next;
		i++;
	}
}

void	a_target_node(t_stack_node *a, t_stack_node *b)
{
	long			n;
	t_stack_node	*tmp;
	t_stack_node	*target;

	while (a)
	{
		n = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (tmp->nbr < a->nbr && tmp->nbr > n)
			{
				n = tmp->nbr;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (n == LONG_MIN)
			a->target_node = findmax(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	b_target_node(t_stack_node *a, t_stack_node *b)
{
	long			n;
	t_stack_node	*tmp;
	t_stack_node	*target;

	while (b)
	{
		n = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->nbr > b->nbr && tmp->nbr < n)
			{
				n = tmp->nbr;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (n == LONG_MAX)
			b->target_node = findmin(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	cheapestn(t_stack_node *s)
{
	long			cheap;
	t_stack_node	*cheap_node;

	cheap_node = NULL;
	if (!s)
		return ;
	cheap = LONG_MAX;
	while (s)
	{
		if (s->cost < cheap)
		{
			cheap = s->cost;
			cheap_node = s;
		}
		s = s->next;
	}
	cheap_node->cheapest = true;
}
