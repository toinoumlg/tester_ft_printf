#ifndef TESTER_FT_PRINTF_H
# define TESTER_FT_PRINTF_H

#include "../../ft_printf.h"
#include <fcntl.h>

int main(int ac, char **av);
void run_test_c();
int compare_files(const char *file1, const char *file2);
void capture_output_to_file(const char *filename, int (*func)(const char *, ...), const char *format, ...);
int capture_compare();

#endif