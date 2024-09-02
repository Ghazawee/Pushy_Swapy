/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:55:01 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 19:05:51 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	if (size && count > (SIZE_MAX / size))
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		j;
	int		i;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc((i + j + 1) * 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*one_big_str(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	*bstr;

	bstr = ft_strdup(" ");
	i = 1;
	while (i < ac)
	{
		if (only_space(av[i]) == 1)
		{
			free(bstr);
			return (NULL);
		}
		tmp = bstr;
		bstr = ft_strjoin(bstr, av[i]);
		free(tmp);
		tmp = bstr;
		bstr = ft_strjoin(bstr, " ");
		free(tmp);
		i++;
	}
	return (bstr);
}
