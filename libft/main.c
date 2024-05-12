/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:15:29 by misoares          #+#    #+#             */
/*   Updated: 2024/05/12 19:29:34 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* int	main(void)
{
	int		i;
	char	*str = ft_strdup("HEY BROTHER!!");

	printf("%s\n", str);
	i = 0;
	if (!str)
	{
		printf("NULL");
		return (0);
	}
	while (str[i])
	{
		printf("%s\n", str[i]);
		free(str[i++]);
	}
	free(str);
	return (0);
} */

/* int	main(void) -- Tests ft_split
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
} */

void print_list(t_list *head)
{
	t_list *current = head;
	printf("List content: ");
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	*lst_toupper(void *tmp)
{
	int i;
	char *str = (char *)tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	tmp = (void *)str;
	return (tmp);
}

int main (void)
{
	t_list *head = NULL;
	t_list *newlst;
	t_list	*current;

	

	t_list *node1 = ft_lstnew(ft_strdup("Node 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Node 3"));
	

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);


	printf("After adding the new nodes: ");
	print_list(head);
	printf("List size: %i", ft_lstsize(head));
	printf("\n");
 
	t_list *newcontent = ft_lstnew(ft_strdup("New node added in front"));
	ft_lstadd_front(&head, newcontent);
	printf("After adding the one new node: \n");
	print_list(head);
	printf("\n");
	printf("New list size: %i", ft_lstsize(head));
	printf("\n");
	
	printf("Last node: ");
	print_list(ft_lstlast(head));
	printf("\n");

	newlst = ft_lstmap(head, lst_toupper, free);
	printf("New list with lstmap:");
	printf("\n");
	print_list(newlst);
	printf("\n");

	ft_lstclear(&head, free);
	while (newlst)
	{
		current = newlst;
		newlst = (newlst)->next;
		free(current);
	}
	newlst = NULL;
	return (0);
}
 
/* int main(void)
{
	char *str;
	int nb;

	str = "Test string";
	nb = 651687;
	ft_putendl_fd(str, 1); // tests itself, putchar and putstr.
	ft_putnbr_fd(nb, 1);
	write(1, "\n", 1);

	return (0);
} */

/* int main(void)
{
	char *str = " ABCDEACDB";
	char *set = "ACB";
	char *newstr = ft_strtrim(str, set);

	
	printf("Original string: %s\n", str);
	printf("New string: %s\n", newstr);
} */

/* int main(void)
{
	const char *string = "Test string";
	const char *string2 = "Test string";

	char *src = (char *)malloc(strlen(string) + 10);
	char *src2 = (char *)malloc(strlen(string2) + 1);

	strcpy(src, string);
	strcpy(src2, string2);

	memmove(src2 + 3, src2, strlen(src2) + 1);
	printf("original memmove: |%s|\n", src2);

	ft_memmove(src + 3, src, strlen(src) + 1);
	printf("ft_memmove: |%s|\n", src);

	free(src);
	free(src2);
} */