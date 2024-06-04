/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:30:42 by misoares          #+#    #+#             */
/*   Updated: 2024/06/04 19:40:14 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buff[i] && i < BUFFER_SIZE)
		{
			if (list->str_buff[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void    dealloc(t_list **list, t_list *clean_node, char *buff)
{
    t_list *tmp;
    
    if (*list == NULL)
        return ;
    while (*list)
    {
        tmp = (*list)->next;
        free((*list)->str_buff);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if (clean_node->str_buff[0])
        *list = clean_node;
    else
    {
        free(buff);
        free(clean_node);
    }
}

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int len_nline(t_list *list)
{
    int i;
    int len;
    
    if (list == NULL)
        return (0);
    len = 0;
    while (list)
    {
        i = 0;
        while (list->str_buff[i] != '\0')
        {
            if (list->str_buff[i] == '\n')
            {
                ++len;
                return (len);
            }
            ++i;
            ++len;
        }
        list = list->next;
    }
    return (len);
}

void    copy_str(t_list *list, char *str)
{
    int i;
    int k;
    
    if (list == NULL)
        return ;
    k = 0;
    while (list)
    {
        i = 0;
        while (list->str_buff[i] != '\0')
        {
            if (list->str_buff[i] == '\n')
            {
                str[k++] = '\n';
                str[k] = '\0';
                return ;
            }
            str[k++] = list->str_buff[i++];
        }
        list = list->next;
    }
    str[k] = '\0';
}
