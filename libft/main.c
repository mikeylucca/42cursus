/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:15:29 by misoares          #+#    #+#             */
/*   Updated: 2024/05/06 17:29:07 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	*str;
	char	**strss;

	str = "Lorem ipsum dolor sit amet,. consectetur adipiscing elit. Mauris vel pharetra quam. Sed sed libero eget mi viverra hendrerit non ut est. Donec eros turpis, cursus eget mauris eu, malesuada volu\0tpat odio. Phasellus lacinia velit sem, eget vehicula nibh pretium at. Donec sit amet elit eget orci euismod ultrices sed non felis. Nulla id tortor tincidunt est fringilla ullamcorper. Curabitur non luctus urna. Aliquam congue tincidunt orci. Maecenas et tincidunt leo. Proin placerat euismod condimentum. Morbi vitae massa ultricies, vestibulum lacus et, accumsan nisi. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Mauris et nisi at nisl iaculis ornare et eu metus. Fusce ut quam molestie, egestas tellus et, molestie nibh. Donec condimentum dui vel odio sodales, eget iaculis quam varius. Cras vitae libero accumsan diam euismod aliquet sit amet nec tellus. Etiam vestibulum diam facilisis pulvinar consectetur. Duis vel lorem pulvinar, hendrerit mi ac, scelerisque arcu. Nam pharetra non tellus ut tincidunt. Donec lacinia sagittis odio quis porttitor. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.";
	strss = ft_split(str, '.');
	i = -1;
	while (strss[++i])
	{
		printf("%s\n", strss[i]);
		free(strss[i]);
	}
	free(strss);
	return (0);
}