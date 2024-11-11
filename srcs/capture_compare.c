#include "../include/tester_ft_printf.h"

void capture_output_to_file(const char *filename, int (*func)(const char *, ...), const char *format, ...) 
{
    int fd;
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) 
	{
        perror("Failed to open file");
        return;
    }

    int stdout_backup = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(fd);

    va_list args;
    va_start(args, format);
    func(format, args);
    va_end(args);

    dup2(stdout_backup, STDOUT_FILENO);
    close(stdout_backup);
}

int compare_files(const char *file1, const char *file2) 
{
    FILE *f1;
	FILE *f2;
	
	f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");
    
	if (!f1 || !f2) 
	{
        perror("Error opening files");
        return -1;
    }

    char ch1, ch2;
    int result = 0;
    while ((ch1 = fgetc(f1)) != EOF && (ch2 = fgetc(f2)) != EOF) 
	{
        if (ch1 != ch2) 
		{
            result = 1;
            break;
        }
    }

    if (ch1 != ch2) 
		result = 1;

    fclose(f1);
    fclose(f2);
    return result;
}

int capture_compare()
{
	capture_output_to_file("ft_printf_output.txt", ft_printf, "Hello %s", "World");
    capture_output_to_file("printf_output.txt", printf, "Hello %s", "World");

	if (compare_files("ft_printf_output.txt", "printf_output.txt") == 0)
    {
        remove("ft_printf_output.txt");
        remove("printf_output.txt");
        return 0;
    }
    else
    {
        remove("ft_printf_output.txt");
        remove("printf_output.txt");
        return 1;
    }
    return 0;
}