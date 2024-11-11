#include "../include/tester_ft_printf.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	if (av[1][0] == 'p')
		run_test_c();
}