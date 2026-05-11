/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-u <jperez-u@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:01:06 by jperez-u          #+#    #+#             */
/*   Updated: 2026/05/11 20:25:12 by jperez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				clean_list(t_list **list);
char				*extract_line(t_list *list);
void				read_to_list(int fd, t_list **list);
void				append_node(t_list **list, char *buffer);
char				*ft_strdup(const char *s1);
int					found_newline(t_list *list);
size_t				len_size(t_list *lst);
t_list				*ft_listlast(t_list *list);
void				free_mem(t_list **list, t_list *leftover_node, char *buf);

#endif