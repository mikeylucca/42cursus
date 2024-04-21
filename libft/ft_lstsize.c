/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:26:22 by misoares          #+#    #+#             */
/*   Updated: 2024/04/21 15:28:17 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int lst_size;

    lst_size = 0;
    if (!lst)
        return (0);
    while (lst != NULL)
    {
        lst = lst->next;
        lst_size++;
    }
    return (lst_size);
}
