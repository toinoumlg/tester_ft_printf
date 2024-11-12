#ifndef TESTER_FT_PRINTF_H
# define TESTER_FT_PRINTF_H


#include "../../ft_printf.h"
#include <fcntl.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

int main(int ac, char **av);
void run_test_c();
int compare_files(const char *file1, const char *file2);
void capture_output_to_file(const char *filename, int (*func)(const char *, ...), const char *format, ...);
int capture_compare();

#endif