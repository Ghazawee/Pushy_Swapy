/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:09:36 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:08:32 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	long	r;
	int		i;
	int		sign;

	i = 0;
	r = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r * sign);
}

bool	stack_sorted(t_stack_node *s)
{
	if (s == NULL)
		return (1);
	while (s->next)
	{
		if (s->nbr > s->next->nbr)
			return (false);
		s = s->next;
	}
	return (true);
}

void	push_cost(t_stack_node *a, t_stack_node *b)
{
	int	alen;
	int	blen;

	alen = stack_len(a);
	blen = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->a_median))
			a->cost = alen - (a->index);
		if (a->target_node->a_median)
			a->cost += a->target_node->index;
		else
			a->cost += blen - (a->target_node->index);
		a = a->next;
	}
}

t_stack_node	*findmin(t_stack_node *s)
{
	long			n;
	t_stack_node	*min;

	n = LONG_MAX;
	min = s;
	while (s)
	{
		if (s->nbr < n)
		{
			n = s->nbr;
			min = s;
		}
		s = s->next;
	}
	return (min);
}

t_stack_node	*findmax(t_stack_node *s)
{
	long			n;
	t_stack_node	*max;

	n = LONG_MIN;
	max = s;
	while (s)
	{
		if (s->nbr > n)
		{
			n = s->nbr;
			max = s;
		}
		s = s->next;
	}
	return (max);
}
