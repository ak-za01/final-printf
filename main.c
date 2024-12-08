#include <stdio.h>
#include <limits.h>
#include <string.h>

// Declare ft_printf prototype
int ft_printf(const char *format, ...);

// ANSI color codes
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

void print_result(int result)
{
    if (result == 0)
        printf(GREEN "PASS\n" RESET);
    else
        printf(RED "FAIL\n" RESET);
}

void test_printf()
{
    int ret_ft, ret_orig;

    printf(YELLOW "=== Testing ft_printf ===\n" RESET);

    // Test %c
    printf(BLUE "[%%c Test]\n" RESET);
    ret_ft = ft_printf("Char: %c\n", 'A');
    ret_orig = printf("Char: %c\n", 'A');
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %s
    printf(BLUE "[%%s Test]\n" RESET);
    ret_ft = ft_printf("String: %s\n", "Hello, world!");
    ret_orig = printf("String: %s\n", "Hello, world!");
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %p
    printf(BLUE "[%%p Test]\n" RESET);
    void *ptr = &ret_ft;
    ret_ft = ft_printf("Pointer: %p\n", ptr);
    ret_orig = printf("Pointer: %p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %d and %i
    printf(BLUE "[%%d and %%i Test]\n" RESET);
    ret_ft = ft_printf("Decimal: %d, Integer: %i\n", 123, -456);
    ret_orig = printf("Decimal: %d, Integer: %i\n", 123, -456);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %u
    printf(BLUE "[%%u Test]\n" RESET);
    ret_ft = ft_printf("Unsigned: %u\n", UINT_MAX);
    ret_orig = printf("Unsigned: %u\n", UINT_MAX);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %x and %X
    printf(BLUE "[%%x and %%X Test]\n" RESET);
    ret_ft = ft_printf("Hexadecimal (lowercase): %x, Uppercase: %X\n", 0xabcdef, 0xABCDEF);
    ret_orig = printf("Hexadecimal (lowercase): %x, Uppercase: %X\n", 0xabcdef, 0xABCDEF);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Test %%
    printf(BLUE "[%%%% Test]\n" RESET);
    ret_ft = ft_printf("Percent: %%\n");
    ret_orig = printf("Percent: %%\n");
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    // Edge cases
    printf(YELLOW "=== Edge Cases ===\n" RESET);

    printf(BLUE "[Null string test for %%s]\n" RESET);
    ret_ft = ft_printf("Null string: %s\n", (char *)NULL);
    ret_orig = printf("Null string: %s\n", (char *)NULL);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);

    printf(BLUE "[Large numbers for %%d and %%u]\n" RESET);
    ret_ft = ft_printf("Large values: %d, %u\n", INT_MIN, UINT_MAX);
    ret_orig = printf("Large values: %d, %u\n", INT_MIN, UINT_MAX);
    printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_orig);
    print_result(ret_ft != ret_orig);
}

int main()
{
    test_printf();
    return 0;
}
