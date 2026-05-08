/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:52:43 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/08 21:01:37 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	line_len(t_list *list)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && list->str_buf[i] != '\n')
		{
			len++;
			i++;
		}
		if (list->str_buf[i] == '\n')
			return (len + 1);
		list = list->next;
	}
	return (len);
}

static void	copy_line(char *line, t_list *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->str_buf[j] && list->str_buf[j] != '\n')
			line[i++] = list->str_buf[j++];
		if (list->str_buf[j] == '\n')
		{
			line[i++] = '\n';
			break ;
		}
		list = list->next;
	}
	line[i] = '\0';
}

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	found_newline(t_list *list)
{
	size_t	i;

	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
