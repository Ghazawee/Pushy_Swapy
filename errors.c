/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:07:47 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:02:44 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] >= '0' && s[i + 1] <= '9')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duperr(t_stack_node *s, int n)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->nbr == n)
			return (1);
		s = s->next;
	}
	return (0);
}

void	frees(t_stack_node **s)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!s)
		return ;
	current = *s;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*s = NULL;
}

void	ft_error(t_stack_node **s, char **arr, char *str, int len)
{
	ft_free_arr_str(str, arr, len);
	frees(s);
	write(2, "Error\n", 6);
	exit(1);
}
