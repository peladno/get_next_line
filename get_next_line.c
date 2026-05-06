/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:54:45 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/06 18:03:58 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// append_node(stash, buffer, bytes_read)
// Agrega un nodo al final.

// found_newline(stash)
// Recorre la lista y detecta si existe un \n.

// extract_line(stash)
// Construye la línea completa recorriendo nodos.

// stash_trim(stash)
// Elimina los nodos usados y deja solo lo que sobra.

// free_stash(stash)
// Libera toda la lista si hay error.

// read_to_stash(fd, stash)
// Igual que antes, pero usando nodos.

/*get_next_line
	↓
read_to_stash
	↓
[ "Hola " ] -> [ "mundo\n" ] -> [ "Co" ]
	↓
extract_line
	↓
"Hola mundo\n"
	↓
stash_trim
	↓
[ "Co" ]
	↓
return line*/

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
	{
		return (NULL);
	}
	/*Construir la línea completa recorriendo la lista */
	line = extract_line(stash);
	if (!line)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	/*Recortar la lista dejando solo lo que sobra */
	stash = stash_trim(stash);
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