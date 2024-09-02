/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preinits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:46:16 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 19:24:55 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_space(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (1);
	while (s[i] == 32 && s[i])
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	ft_free_arr_str(char *str, char **array, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(array[i]);
		i++;
	}
	free(str);
	free(array);
}

void	preinit_stack(t_stack_node **a, int ac, char **av)
{
	char	**big_sml_str;
	char	*big_str;
	int		len;

	big_str = one_big_str(ac, av);
	if (!big_str)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	big_sml_str = ft_split((const char *)big_str, ' ');
	len = ft_wount(big_str, ' ');
	inzsa(a, big_sml_str, big_str, len);
	ft_free_arr_str(big_str, big_sml_str, len);
}
