/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:35:41 by misoares          #+#    #+#             */
/*   Updated: 2024/04/21 16:07:16 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (!lst)
        return ;
    if (*lst)
    {
        tmp = *lst;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}
