/* Use the character classification functions to prepare an implementation of atoi(); have
this version return the value of 0 if the input string is not a pure number.*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    const char *test1 = "12345";
    const char *test2 = "  -6789";
    const char *test3 = "42abc";
    const char *test4 = "   +987";
    const char *test5 = "abc123";

    printf("String: '%s' -> Integer: %d\n", test1, my_atoi(test1));
    printf("String: '%s' -> Integer: %d\n", test2, my_atoi(test2));
    printf("String: '%s' -> Integer: %d\n", test3, my_atoi(test3)); // Invalid input
    printf("String: '%s' -> Integer: %d\n", test4, my_atoi(test4));
    printf("String: '%s' -> Integer: %d\n", test5, my_atoi(test5)); // Invalid input

    return 0;

}

int my_atoi(char *str)
{
    int sign = 1;
    int result;
    // skip any leading whitespace
    while(isspace(*str))
    {
        str++;
    }
    // check for sign
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
        {
            sign = -1;
        }
        *str++;
    }
    while(*str)
    {
        if(isdigit(*str))
        {
            result = ((int)(*str) - (int)('0')) + result*10;
        }
        else
        {
            return 0;
        }
        str++;
    }
    return result*sign;
}