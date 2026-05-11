/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:58:18 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/11 20:30:59 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
get_next_line.c get_next_line_utils.c main.c -o gnl*/
// TODO test project

#include "get_next_line.h"

static void	test_file(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file: %s\n", filename);
		return ;
	}
	printf("===== Testing: %s =====\n", filename);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("[%d] %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./gnl <file1> ...\n");
		return (1);
	}
	while (*++argv)
		test_file(*argv);
	return (0);
}