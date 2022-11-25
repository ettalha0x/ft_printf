#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *s;
	s = "hello";
	ft_printf("|%#x|\n", 0);
	printf("|%#x|\n", 0);

	// ft_printf("|% d|\n",10);
	// ft_printf("|% i|\n",10);


	// ft_printf("|%+d|\n",10);
	// ft_printf("|%+i|\n",10);
}
