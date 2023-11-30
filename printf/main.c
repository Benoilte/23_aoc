/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:47:48 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/02 11:12:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	test_print_char(void);
// void	test_print_percent(void);
void	test_print_string(void);
void	test_print_hex_lowercase(void);
void	test_print_hex_uppercase(void);
void	test_print_uint(void);
void	test_print_decimal(void);
void	test_print_integer_as_decimal(void);
void	test_print_integer_as_hex(void);
void	test_print_integer_as_oct(void);
void	test_print_ptr(void);

int		main(void)
{
	test_print_char();
	// test_print_percent();
	test_print_string();
	test_print_hex_lowercase();
	test_print_hex_uppercase();
	test_print_uint();
	test_print_decimal();
	test_print_integer_as_decimal();
	test_print_integer_as_hex();
	test_print_integer_as_oct();
	test_print_ptr();
	return (0);
}

void	test_length(int	printf_len, int ft_printf_len)
{
	if (printf_len - ft_printf_len)
		ft_printf("\033[31mlength are different, printf_len: %d and ft_printf_len: %d\033[0m\n", printf_len, ft_printf_len);
	else
		ft_printf("\033[32mlength are the same\033[0m\n");
}

void	test_print_char(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print char  ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a char:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%c]\n", 'a');
	printf_len = printf("***printf: [%c]\n", 'a');
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print char with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10c]\n", 'a');
	printf_len = printf("***printf: [%-10c]\n", 'a');
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print char with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10c]\n", 'a');
	printf_len = printf("***printf: [%10c]\n", 'a');
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print char with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10c]  [%-10c]  [%42c]\n", 'a', 'b', 'c');
	printf_len = printf("***printf: [%10c]  [%-10c]  [%42c]\n", 'a', 'b', 'c');
	test_length(printf_len, ft_printf_len);
}

// void	test_print_percent(void)
// {
// 	int	ft_printf_len;
// 	int	printf_len;

// 	printf("\n\033[36m ----------- Test print percent ----------- \033[0m\n");
// 	ft_printf("\n\033[33mprint only a percent:\033[0m\n");
// 	ft_printf_len = ft_printf("ft_printf: [%%]\n");
// 	printf_len = printf("***printf: [%%]\n");
// 	test_length(printf_len, ft_printf_len);

// 	printf("\n\033[33mTest print percent with flag '-' width of 10:\033[0m\n");
// 	ft_printf_len = ft_printf("ft_printf: [%-10%]\n");
// 	printf_len = printf("***printf: [%-10%]\n");
// 	test_length(printf_len, ft_printf_len);

// 	printf("\n\033[33mTest print percent with no flags and width of 10:\033[0m\n");
// 	ft_printf_len = ft_printf("ft_printf: [%10%]\n");
// 	printf_len = printf("***printf: [%10%]\n");
// 	test_length(printf_len, ft_printf_len);

// 	ft_printf("\n\033[33mTest print percent with several value:\033[0m\n");
// 	ft_printf_len = ft_printf("ft_printf: [%10%]  [%-10%]  [%42%]\n");
// 	printf_len = printf("***printf: [%10%]  [%-10%]  [%42%]\n");
// 	test_length(printf_len, ft_printf_len);
// }

void	test_print_string(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\n\033[36m ----------- Test print string ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a string:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%s]\n", "coucou");
	printf_len = printf("***printf: [%s]\n", "coucou");
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mprint a string, in a string:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%s], comment ça va?\n", "coucou");
	printf_len = printf("***printf: [%s], comment ça va?\n", "coucou");
	test_length(printf_len, ft_printf_len);

	// ft_printf("\n\033[33mTest print string NULL value\033[0m\n");
	// ft_printf_len = ft_printf("ft_printf: [%10s]\n", NULL);
	// printf_len = printf("***printf: [%10s]\n", NULL);
	// test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print string with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10s]\n", "coucou");
	printf_len = printf("***printf: [%-10s]\n", "coucou");
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print string with flag '-' width of 10 and precision of 3:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10.3s]\n", "coucou");
	printf_len = printf("***printf: [%-10.3s]\n", "coucou");
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print string with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10s]\n", "coucou");
	printf_len = printf("***printf: [%10s]\n", "coucou");
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print string with no flags, width of 10 and precision of 3:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.3s]\n", "coucou");
	printf_len = printf("***printf: [%10.3s]\n", "coucou");
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print string with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10s]  [%-10s]  [%42s]  [%10.3s]  [%-10s]\n", "coucou", "coucou", "coucou", "coucou", "coucou");
	printf_len = printf("***printf: [%10s]  [%-10s]  [%42s]  [%10.3s]  [%-10s]\n", "coucou", "coucou", "coucou", "coucou", "coucou");
	test_length(printf_len, ft_printf_len);
}

void	test_print_hex_lowercase(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print hex with x ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a hex:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%x]\n", 42);
	printf_len = printf("***printf: [%x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10x]\n", 42);
	printf_len = printf("***printf: [%-10x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10x]\n", 42);
	printf_len = printf("***printf: [%10x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flag '0' flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%010x]\n", 42);
	printf_len = printf("***printf: [%010x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flags '0', '#' flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%0#10x]\n", 42);
	printf_len = printf("***printf: [%0#10x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '-', '#' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-#10x]\n", 42);
	printf_len = printf("***printf: [%-#10x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '-', '#', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-#10.5x]\n", 42);
	printf_len = printf("***printf: [%-#10.5x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '#', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%#10.5x]\n", 42);
	printf_len = printf("***printf: [%#10.5x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.5x]\n", 42);
	printf_len = printf("***printf: [%10.5x]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no width value 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [ %x ]\n", 0);
	printf_len = printf("***printf: [ %x ]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no width value 0 and flag #:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [ %#x ]\n", 0);
	printf_len = printf("***printf: [ %#x ]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0x]\n", 0);
	printf_len = printf("***printf: [%.0x]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision flag . but no hex value and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.x]\n", 0);
	printf_len = printf("***printf: [%.x]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 5 precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%5.0x]\n", 0);
	printf_len = printf("***printf: [%5.0x]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 5 flag '-' precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-5.0x]\n", 0);
	printf_len = printf("***printf: [%-5.0x]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision of 0 and value of 42:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0x]\n", 42);
	printf_len = printf("***printf: [%.0x]\n", 42);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print hex with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10x]  [%-10x]  [%42x]  [%010x]  [%0#10x]  [%-#10x] [%-#10.5x]  [%#10.5x]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	printf_len = printf("***printf: [%10x]  [%-10x]  [%42x]  [%010x]  [%0#10x]  [%-#10x] [%-#10.5x]  [%#10.5x]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	test_length(printf_len, ft_printf_len);
}

void	test_print_hex_uppercase(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print hex with X ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a hex:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%X]\n", 42);
	printf_len = printf("***printf: [%X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10X]\n", 42);
	printf_len = printf("***printf: [%-10X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10X]\n", 42);
	printf_len = printf("***printf: [%10X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flag '0' flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%010X]\n", 42);
	printf_len = printf("***printf: [%010X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with flags '0', '#' flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%0#10X]\n", 42);
	printf_len = printf("***printf: [%0#10X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '-', '#' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-#10X]\n", 42);
	printf_len = printf("***printf: [%-#10X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '-', '#', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-#10.5X]\n", 42);
	printf_len = printf("***printf: [%-#10.5X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with '#', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%#10.5X]\n", 42);
	printf_len = printf("***printf: [%#10.5X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.5X]\n", 42);
	printf_len = printf("***printf: [%10.5X]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no width value 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [ %X ]\n", 0);
	printf_len = printf("***printf: [ %X ]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with no width value 0 and flag #:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [ %#X ]\n", 0);
	printf_len = printf("***printf: [ %#X ]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0X]\n", 0);
	printf_len = printf("***printf: [%.0X]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision flag . but no hex value and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.X]\n", 0);
	printf_len = printf("***printf: [%.X]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 5 precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%5.0X]\n", 0);
	printf_len = printf("***printf: [%5.0X]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with width of 5 flag '-' precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-5.0X]\n", 0);
	printf_len = printf("***printf: [%-5.0X]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print hex with precision of 0 and value of 42:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0X]\n", 42);
	printf_len = printf("***printf: [%.0X]\n", 42);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print hex with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10X]  [%-10X]  [%42X]  [%010X]  [%0#10X]  [%-#10X] [%-#10.5X]  [%#10.5X]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	printf_len = printf("***printf: [%10X]  [%-10X]  [%42X]  [%010X]  [%0#10X]  [%-#10X] [%-#10.5X]  [%#10.5X]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	test_length(printf_len, ft_printf_len);
}

void	test_print_uint(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print unsigned int ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a unsigned int:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%u]\n", 42);
	printf_len = printf("***printf: [%u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10u]\n", 42);
	printf_len = printf("***printf: [%-10u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10u]\n", 42);
	printf_len = printf("***printf: [%10u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with flag '0' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%010u]\n", 42);
	printf_len = printf("***printf: [%010u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with '-' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10u]\n", 42);
	printf_len = printf("***printf: [%-10u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with '-', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10.5u]\n", 42);
	printf_len = printf("***printf: [%-10.5u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.5u]\n", 42);
	printf_len = printf("***printf: [%10.5u]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with no width value 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [ %u ]\n", 0);
	printf_len = printf("***printf: [ %u ]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0u]\n", 0);
	printf_len = printf("***printf: [%.0u]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with precision flag . but no unsigned int value and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.u]\n", 0);
	printf_len = printf("***printf: [%.u]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with width of 5 precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%5.0u]\n", 0);
	printf_len = printf("***printf: [%5.0u]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with width of 5 flag '-' precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-5.0u]\n", 0);
	printf_len = printf("***printf: [%-5.0u]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print unsigned int with precision of 0 and value of 42:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0u]\n", 42);
	printf_len = printf("***printf: [%.0u]\n", 42);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print unsigned int with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10u]  [%-10u]  [%42u]  [%010u]  [%010u]  [%-10u] [%-10.5u]  [%10.5u]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	printf_len = printf("***printf: [%10u]  [%-10u]  [%42u]  [%010u]  [%010u]  [%-10u] [%-10.5u]  [%10.5u]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	test_length(printf_len, ft_printf_len);
}

void	test_print_decimal(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print decimal ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a decimal:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%d] [%d] [%d] [%d] [%d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%d] [%d] [%d] [%ld] [%d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10d] [%-10d] [%-10d] [%-10d] [%-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10d] [%-10d] [%-10d] [%-10ld] [%-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '+' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%+10d] [%+10d] [%+10d] [%+10d] [%+10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%+10d] [%+10d] [%+10d] [%+10ld] [%+10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flags '+', '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%+-10d] [%+-10d] [%+-10d] [%+-10d] [%+-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%+-10d] [%+-10d] [%+-10d] [%+-10ld] [%+-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flags ' ', '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [% -10d] [% -10d] [% -10d] [% -10d] [% -10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [% -10d] [% -10d] [% -10d] [% -10ld] [% -10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flags ' ' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [% 10d] [%+-10d] [%+-10d] [%+-10d] [%+-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [% 10d] [%+-10d] [%+-10d] [%+-10ld] [%+-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10d] [%10d] [%10d] [%10d] [%10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%10d] [%10d] [%10d] [%10ld] [%10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '0' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%010d] [%010d] [%010d] [%09d] [%09d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%010d] [%010d] [%010d] [%09ld] [%09d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with '-' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10d] [%-10d] [%-10d] [%-10d] [%-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10d] [%-10d] [%-10d] [%-10ld] [%-10d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with '-', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10.5d] [%-10.5d] [%-10.5d] [%-10.5d] [%-10.5d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10.5d] [%-10.5d] [%-10.5d] [%-10.5ld] [%-10.5d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with width of 10 and precison of 0 - 3 - 4 - 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.5d] [%10.d] [%10.3d] [%10.4d] [%10.5d]\n", 42, -42, -42, -42, -42);
	printf_len = printf("***printf: [%10.5d] [%10.d] [%10.3d] [%10.4d] [%10.5d]\n", 42, -42, -42, -42, -42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with width of 42 flag ' ', '0' and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [42% 042d42]\n", 0);
	printf_len = printf("***printf: [42% 042d42]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with width of 42 flag '+', '0' and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [42%+042d42]\n", 0);
	printf_len = printf("***printf: [42%+042d42]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0d]\n", 0);
	printf_len = printf("***printf: [%.0d]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with precision flag . but no decimal value and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.d]\n", 0);
	printf_len = printf("***printf: [%.d]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with width of 5 precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%5.0d]\n", 0);
	printf_len = printf("***printf: [%5.0d]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with width of 5 flag '-' precision of 0 and value of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-5.0d]\n", 0);
	printf_len = printf("***printf: [%-5.0d]\n", 0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with precision of 0 and value of 42:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%.0d]\n", 42);
	printf_len = printf("***printf: [%.0d]\n", 42);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag ' ', '0' and width of 36 and value of -843442790:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [^.^/% 036d^.^/]\n", -843442790);
	printf_len = printf("***printf: [^.^/% 036d^.^/]\n", -843442790);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '+' and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '%+.d', %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '%+.d', %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '+' width 5 and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '%+5.d', %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '%+5.d', %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '+', '-' and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '%-+.d', %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '%-+.d', %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag '+', '-' width 5 and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '%+-5.d', %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '%+-5.d', %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d, %+-5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	// printf("\n\033[33mTest print decimal with flag '+', '0' width of 5 and precision of 0:\033[0m\n");
	// ft_printf_len = ft_printf("ft_printf: '%+0.d', %+0.d, %+0.d, %+0.d, %+0.d, %+0.d, %+0.d, %+0.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// printf_len = printf("***printf: '%+0.d', %+0.d, %+0.d, %+0.d, %+0.d, %+0.d, %+0.d, %+0.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// test_length(printf_len, ft_printf_len);

	// printf("\n\033[33mTest print decimal with flag '+', '0' width of 5 and precision of 0:\033[0m\n");
	// ft_printf_len = ft_printf("ft_printf: '%+05.d', %+05.d, %+05.d, %+05.d, %+05.d, %+05.d, %+05.d, %+05.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// printf_len = printf("***printf: '%+05.d', %+05.d, %+05.d, %+05.d, %+05.d, %+05.d, %+05.d, %+05.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag ' ' and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '% .d', % .d, % .d, % .d, % .d, % .d, % .d, % .d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '% .d', % .d, % .d, % .d, % .d, % .d, % .d, % .d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print decimal with flag ' ' width of 5 and precision of 0:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: '% 5.d', % 5.d, % 5.d, % 5.d, % 5.d, % 5.d, % 5.d, % 5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf_len = printf("***printf: '% 5.d', % 5.d, % 5.d, % 5.d, % 5.d, % 5.d, % 5.d, % 5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print decimal with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10d]  [%-10d]  [%42d]  [%010d]  [%010d]  [%-10d] [%-10.5d]  [%10.5d]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	printf_len = printf("***printf: [%10d]  [%-10d]  [%42d]  [%010d]  [%010d]  [%-10d] [%-10.5d]  [%10.5d]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	test_length(printf_len, ft_printf_len);
}

void	test_print_integer_as_decimal(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print integer as decimal ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a integer as decimal:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%i] [%i] [%i] [%i] [%i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%i] [%i] [%i] [%li] [%i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10i] [%-10i] [%-10i] [%-10i] [%-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10i] [%-10i] [%-10i] [%-10li] [%-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flag '+' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%+10i] [%+10i] [%+10i] [%+10i] [%+10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%+10i] [%+10i] [%+10i] [%+10li] [%+10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flags '+', '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%+-10i] [%+-10i] [%+-10i] [%+-10i] [%+-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%+-10i] [%+-10i] [%+-10i] [%+-10li] [%+-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flags ' ', '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [% -10i] [% -10i] [% -10i] [% -10i] [% -10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [% -10i] [% -10i] [% -10i] [% -10li] [% -10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flags ' ' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [% 10i] [%+-10i] [%+-10i] [%+-10i] [%+-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [% 10i] [%+-10i] [%+-10i] [%+-10li] [%+-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i] [%10i] [%10i] [%10i] [%10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%10i] [%10i] [%10i] [%10li] [%10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with flag '0' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%010i] [%010i] [%010i] [%09d] [%09d]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%010i] [%010i] [%010i] [%09li] [%09d]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with '-' and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10i] [%-10i] [%-10i] [%-10i] [%-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10i] [%-10i] [%-10i] [%-10li] [%-10i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with '-', width of 10 and precison of 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10.5i] [%-10.5i] [%-10.5i] [%-10.5i] [%-10.5i]\n", 42, -42, 0, -2147483648, 2147483647);
	printf_len = printf("***printf: [%-10.5i] [%-10.5i] [%-10.5i] [%-10.5li] [%-10.5i]\n", 42, -42, 0, -2147483648, 2147483647);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as decimal with width of 10 and precison of 0 - 3 - 4 - 5:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10.5i] [%10.i] [%10.3i] [%10.4i] [%10.5i]\n", 42, -42, -42, -42, -42);
	printf_len = printf("***printf: [%10.5i] [%10.i] [%10.3i] [%10.4i] [%10.5i]\n", 42, -42, -42, -42, -42);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print integer as decimal with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i]  [%-10i]  [%42i]  [%010i]  [%010i]  [%-10i] [%-10.5i]  [%10.5i]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	printf_len = printf("***printf: [%10i]  [%-10i]  [%42i]  [%010i]  [%010i]  [%-10i] [%-10.5i]  [%10.5i]\n", 42, 24, 88, 32, -10, -1000, 255, 78632);
	test_length(printf_len, ft_printf_len);
}

void	test_print_integer_as_hex(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print integer as hex  ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a integer as hex:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%i]\n", 0x2a);
	printf_len = printf("***printf: [%i]\n", 0x2a);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as hex with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10i]\n", 0x2a);
	printf_len = printf("***printf: [%-10i]\n", 0x2a);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as hex with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i]\n", 0x2a);
	printf_len = printf("***printf: [%10i]\n", 0x2a);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print integer as hex with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i]  [%-10i]  [%42i]\n", 0x2a, 0xf, 0x66f);
	printf_len = printf("***printf: [%10i]  [%-10i]  [%42i]\n", 0x2a, 0xf, 0x66f);
	test_length(printf_len, ft_printf_len);
}

void	test_print_integer_as_oct(void)
{
	int	ft_printf_len;
	int	printf_len;

	printf("\033[36m ----------- Test print integer as oct  ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a integer as oct:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%i]\n", 052);
	printf_len = printf("***printf: [%i]\n", 052);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as oct with flag '-' width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-10i]\n", 052);
	printf_len = printf("***printf: [%-10i]\n", 052);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print integer as oct with no flags and width of 10:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i]\n", 052);
	printf_len = printf("***printf: [%10i]\n", 052);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print integer as oct with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%10i]  [%-10i]  [%42i]\n", 052, 073, 066);
	printf_len = printf("***printf: [%10i]  [%-10i]  [%42i]\n", 052, 073, 066);
	test_length(printf_len, ft_printf_len);
}

void	test_print_ptr(void)
{
	int	ft_printf_len;
	int	printf_len;
	int	test1;
	int	test2;
	int test3;

	test1 = 35;
	test2 = 5434566;
	test3 = -42;
	printf("\033[36m ----------- Test print ptr  ----------- \033[0m\n");
	ft_printf("\n\033[33mprint only a ptr:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%p]\n", &test1);
	printf_len = printf("***printf: [%p]\n", &test1);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print ptr with flag '-' width of 25:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%-25p]\n", &test2);
	printf_len = printf("***printf: [%-25p]\n", &test2);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print ptr with no flags and width of 25:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%25p]\n", &test3);
	printf_len = printf("***printf: [%25p]\n", &test3);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print ptr with ptr null:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%p]\n", (void *)0);
	printf_len = printf("***printf: [%p]\n", (void *)0);
	test_length(printf_len, ft_printf_len);

	printf("\n\033[33mTest print ptr with ptr null and width of 11:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [42%11p42]\n", (void *)0);
	printf_len = printf("***printf: [42%11p42]\n", (void *)0);
	test_length(printf_len, ft_printf_len);

	ft_printf("\n\033[33mTest print ptr with several value:\033[0m\n");
	ft_printf_len = ft_printf("ft_printf: [%25p]  [%-25p]  [%42p]\n", &test1, &test2, &test3);
	printf_len = printf("***printf: [%25p]  [%-25p]  [%42p]\n", &test1, &test2, &test3);
	test_length(printf_len, ft_printf_len);
}
