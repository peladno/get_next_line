/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:52:43 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/10 20:52:49 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*arr;

	// CHECK I need to check null??
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	found_newline(t_list *list)
{
	while (list)
	{
		if (ft_strchr(list->content, '\n'))
			return (1);
		list = list->next;
	}
	return (0);
}

size_t	len_size(t_list *list)
{
	size_t	len;
	size_t	i;
	t_list	*current;

	len = 0;
	if (!list)
		return (len);
	current = list;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			len++;
			if (current->content[len] == '\n')
				return (len);
			i++;
		}
		current = current->next;
	}
	return (len);
}

t_list	*ft_listlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
