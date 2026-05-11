/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:17:54 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/10 22:31:31 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(buffer);
	if (!new_node->content)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last_node = ft_listlast(*list);
	last_node->next = new_node;
}

void	read_to_list(int fd, t_list **list)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	read_bytes = 1;
	while (!found_newline(*list) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			append_node(list, buffer);
		}
	}
	free(buffer);
}

char	*extract_line(t_list *list)
{
	char	*line;
	char	*str;
	size_t	j;

	if (!list)
		return (NULL);
	line = malloc(sizeof(char) * (len_size(list) + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (list)
	{
		str = list->content;
		while (*str)
		{
			line[j++] = *str;
			if (*str == '\n')
				break ;
			str++;
		}
		list = list->next;
	}
	line[j] = '\0';
	return (line);
}

void	clean_list(t_list **list)
{
	size_t	i;
	size_t	j;
	char	*buff;
	t_list	*last_node;
	t_list	*leftover_node;

	buff = malloc(BUFFER_SIZE + 1);
	leftover_node = malloc(sizeof(t_list));
	if (!buff || !leftover_node)
		return ;
	last_node = ft_listlast(*list);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	j = 0;
	while (last_node->content[i])
		buff[j++] = last_node->content[i++];
	buff[j] = '\0';
	leftover_node->content = buff;
	leftover_node->next = NULL;
	free_mem(list, leftover_node, buff); 
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*list;
	static char		*List = NULL;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_to_list(fd, &list);
	if (!list)
		return (NULL);
	line = extract_line(list);
	clean_list(&list); 
	return (line);
}
