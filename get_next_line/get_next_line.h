/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:17:18 by misoares          #+#    #+#             */
/*   Updated: 2024/06/06 19:15:41 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				dealloc(t_list **list, t_list *clean_node, char *buff);
t_list				*find_last_node(t_list *list);
int					len_nline(t_list *list);
void				copy_str(t_list *list, char *str);
int					found_newline(t_list *list);

#endif