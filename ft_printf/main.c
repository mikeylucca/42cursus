#include "libftprintf.h"

int main(void)
{
	// char *str = "Test string";
	// int nbr = 12334534;
	//unsigned int unbr = 4294967295;
	int *p = 0;

	/* ft_printf("My printf: %s\n", str);
	printf("Original Printf: %s\n", str); */

	ft_printf("Pointer 0 test: %p\n", p);
	printf("Pointer 0 test real printf: %p\n", p);

	return (0);
}