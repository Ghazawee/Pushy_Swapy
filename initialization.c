/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:26:31 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:04:27 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*flastn(t_stack_node *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

void	addnode(t_stack_node **s, int n)
{
	t_stack_node	*node;
	t_stack_node	*ln;

	if (!s)
		return ;
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!*s)
	{
		*s = node;
		node->prev = NULL;
	}
	else
	{
		ln = flastn(*s);
		ln->next = node;
		node->prev = ln;
	}
}

void	inzsa(t_stack_node **s, char **av, char *str, int len)
{
	long	n;
	int		i;

	i = 0;
	if (!s)
		return ;
	while (av[i])
	{
		if (errors(av[i]))
			ft_error(s, av, str, len);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			ft_error(s, av, str, len);
		if (duperr(*s, (int)n))
			ft_error(s, av, str, len);
		addnode(s, (int)n);
		i++;
	}
}

t_stack_node	*find_cheap_node(t_stack_node *s)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	prepush(t_stack_node **s, t_stack_node *head_node, char wstack)
{
	while (*s != head_node)
	{
		if (wstack == 'a')
		{
			if (head_node->a_median)
				ra(s, false);
			else
				rra(s, false);
		}
		else if (wstack == 'b')
		{
			if (head_node->a_median)
				rb(s, false);
			else
				rrb(s, false);
		}
	}
}
