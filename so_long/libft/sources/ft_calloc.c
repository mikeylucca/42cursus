/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:31 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:01:10 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memarea;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb && (nmemb * size / nmemb) != size)
		return (NULL);
	memarea = malloc(nmemb * size);
	if (!memarea)
		return (NULL);
	ft_bzero(memarea, nmemb * size);
	return (memarea);
}

/*
int	main()
{
	char	welp[] = "hello world";

	printf("%s\n", welp);
//	calloc(welp, 3);
	ft_calloc(welp, 3);
	printf("%s", welp);
	return (0);
}
*/
