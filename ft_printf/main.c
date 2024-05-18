#include "libftprintf.h"

int main(void)
{
	char *str = "Test string";
	int nbr = 12334534;
	//unsigned int unbr = 4294967295;

	ft_printf("My printf: %s\n", str);
	printf("Original Printf: %s\n", str);

	ft_printf("My printf: %i\n", nbr);
	printf("Original Printf: %i\n", nbr);

	return (0);
}