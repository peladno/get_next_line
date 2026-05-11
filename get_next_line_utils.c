/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:52:43 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/11 20:40:25 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	int		i;
	char	*arr;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
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
	char	*str;

	while (list)
	{
		str = list->content;
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
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
		return (0);
	current = list;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			len++;
			if (current->content[i] == '\n')
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

void	free_mem(t_list **list, t_list *leftover_node, char *buf)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	if (*buf)
		*list = leftover_node;
	else
	{
		free(buf);
		free(leftover_node);
		*list = NULL;
	}
}
