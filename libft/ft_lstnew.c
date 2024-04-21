/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:56:24 by misoares          #+#    #+#             */
/*   Updated: 2024/04/21 15:09:09 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *new;

    if (!(new = (t_list*)malloc(sizeof(t_list)))) // returns null if the allocation fails
    {
        return (NULL);
    }
    if (new) // runs if allocation is successful
    {
        new->content = content; // assigns content from func to list
        new->next = NULL; // indicates that it is the last item of the list
    }
    return (new);
}
