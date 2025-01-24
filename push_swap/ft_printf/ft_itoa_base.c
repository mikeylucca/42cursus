/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:10:01 by misoares          #+#    #+#             */
/*   Updated: 2024/05/16 17:13:32 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_size(size_t n, int base_len)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(size_t n, int base_len, char *base)
{
	char	*str_n;
	int		len;
	int		i;

	i = 0;
	len = base_size(n, base_len);
	str_n = malloc(sizeof(char) * (len + 1));
	if (!str_n)
		return (NULL);
	str_n[len] = '\0';
	while (n)
	{
		str_n[len - 1] = base[n % base_len];
		n /= base_len;
		len--;
	}
	return (str_n);
}
