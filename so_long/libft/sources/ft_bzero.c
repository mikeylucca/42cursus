/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:35:22 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:46:56 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
int	main()
{
	char	welp[] = "hello world";

	printf("%s\n", welp);
	bzero(welp, 3);
//	ft_bzero(welp, 3);
	printf("%s", welp);
	return (0);
}
*/
