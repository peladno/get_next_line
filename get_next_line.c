/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:17:54 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/10 16:37:11 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1. find_newline(list)✅
//    checks if any node has '\n'

// 2. find_last_node(list)
//    returns the last node

// 3. append_node(&list, buffer)
//    creates a node and adds it to the end

// 4. read_to_list(fd, &list)✅
//    reads until '\n' or EOF

// 5. extract_line(list)
//    creates the final line to return

// 6. clean_list(&list)
//    removes used data and keeps leftover

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
			append_node(list, buffer); // TODO
		}
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*list;
	static char		*List = NULL;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_to_list(fd, &list); // ✅
	if (!list)
		return (NULL);
	line = extract_line(list); // TODO
	clean_list(&list);         // TODO
	return (line);
}
