#include "../include/tester_ft_printf.h"

int main()
{
	char *c = "blabla";
	void *cdr;
	cdr = c;
	printf("Hello %s %x %X %p %u\n", "world", 0, 0, cdr, -3424);
	ft_printf("Hello %s %x %X %p %u\n", "world", 0, 0, cdr, -3424);
    return 0;
}