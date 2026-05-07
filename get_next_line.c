/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:54:45 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/07 22:18:54 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// append_node(list, buffer, bytes_read)
// Agrega un nodo al final.

// found_newline(list)
// Recorre la lista y detecta si existe un \n.

// extract_line(list)
// Construye la línea completa recorriendo nodos.

// list_trim(list)
// Elimina los nodos usados y deja solo lo que sobra.

// free_list(list)
// Libera toda la lista si hay error.

// read_to_list(fd, list)
// Igual que antes, pero usando nodos.

/*get_next_line
	↓
read_to_list
	↓
[ "Hola " ] -> [ "mundo\n" ] -> [ "Co" ]
	↓
extract_line
	↓
"Hola mundo\n"
	↓
list_trim
	↓
[ "Co" ]
	↓
return line*/

t_list	*append_node(t_list *list, char *buf, ssize_t bytes_read)
{
	t_list	*new_node;
	t_list	*last_node;
	ssize_t	i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->str_buf = malloc(bytes_read + 1);
	if (!new_node->str_buf)
		free(new_node);
	return (free(new_node), NULL);
	i = 0;
	while (i < bytes_read)
	{
		new_node->str_buf[i] = buf[i];
		i++;
	}
	new_node->str_buf[i] = '\0';
	new_node->next = NULL;
	last_node = find_last_node(list);
	if (!last_node)
		list = new_node;
	else
		last_node->next = new_node;
	return (list);
}

// t_list	*append_node(t_list *list, char *buf)
// {
// 	t_list	*new_node;
// 	t_list	*last_node;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->str_buf = ft_strdup(buf);
// 	if (!new_node->str_buf)
// 		return (free(new_node), NULL);
// 	new_node->next = NULL;
// 	last_node = find_last_node(list);
// 	if (!last_node)
// 		list = new_node;
// 	else
// 		last_node->next = new_node;
// 	return (list);
// }

t_list	*read_to_list(int fd, t_list *list)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		// TODO free list
		free_list(list);
		return (NULL);
	}
	bytes_read = 1;
	while (!found_newline(list) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free_list(list);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		list = append_node(list, buffer, bytes_read);
	}
	free(buffer);
	return (list);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	list = read_to_list(fd, list);
	if (list == NULL)
	{
		return (NULL);
	}
	/*TODO Construir la línea completa recorriendo la lista */
	line = extract_line(list);
	if (!line)
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	/*TODO Recortar la lista dejando solo lo que sobra */
	list = list_trim(list);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}

// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// 	close(fd);
// 	return (0);
// }