/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:20:35 by misoares          #+#    #+#             */
/*   Updated: 2024/06/04 20:11:37 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    clean_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;
	int i;
	int k;
	char *buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buff == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[i] != '\n')
		i++;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[++i])
		buff[k++] = last_node->str_buff[i];
	buff[k] = '\0';
	clean_node->str_buff = buff;
	clean_node->next = NULL;
	dealloc(list, clean_node, buff);
}

char	*get_line(t_list *list) // gets the whole line until \n
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_nline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buff)
{
	t_list  *new_node;
	t_list  *last_node;
	
	last_node = find_last_node(*list);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
	   *list = new_node;
	else
		last_node->next = new_node;
		
	new_node->str_buff = buff;
	new_node->next = NULL;
}

// creates the list which will store chars up to buffersize

void	create_list(t_list **list, int fd)
{
	int     chars_read;
	char    *buff;

	// scan line if \n is present
	while (!found_newline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1); // + 1 to append \0 in the end
		if (buff == NULL)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == 0)
		{
			free(buff);
			return ;
		}
		buff[chars_read] = '\0';
		append(list, buff); // append the buff in the list
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*nxt_l;

	// read is to know if the file can be opened since it returns -1 if not.
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &nxt_l, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	nxt_l = get_line(list);
	clean_list(&list);
	return (nxt_l);
}
