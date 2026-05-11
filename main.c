/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:58:18 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/09 17:57:06 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 \
get_next_line.c get_next_line_utils.c main.c -o gnl*/
//TODO test project

#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *result;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	result = get_next_line(fd);
	printf("RESULT:\n%s\n", result);
	free(result);
	close(fd);
	return (0);
}