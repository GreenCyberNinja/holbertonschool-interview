#include "holberton.h"

/**
 * main - multiplies two positive numbers and prints them
 * @argc: number of arguments passed to prog
 * @argv: the arguments passed to program
 * Return: 0 or 98 on error
 */
int main(int argc, char *argv[])
{
    char *ans;
    int len, i;

    if (argc != 3 || IsNum(argv[1]) != 0 || IsNum(argv[2]) != 0)
    {
        _puts("Error\n");
        exit(98);
    }
    ans = Multiply(_atoi(argv[1]), _atoi(argv[2]));
    _putchar('\n');
    free(ans);
    return (0);
}
/**
 * _puts - prints a string
 * @str: string to be printed
 * Return: 0 or 1 on fail
 */
int _puts(char *str)
{
	int i, len = _len(str);

	if (str == NULL)
        return (1);

    for (i = 0; i < len; i++)
        _putchar(str[i]);

    return (0);
}
/**
 * IsNum - checks if str is numerical
 * @str: string to check
 * Return: 0 if number or 1 if not
 */
int IsNum(char *str)
{
    int i;
    for (i = 0; i < _len(str); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}
/**
 * _len - gets length of string
 * @str - string to get length of
 * Return: length of string
 */
int _len(char *str)
{
    int len = 0;
    int i;

    for (i = 0; str[i]; i++)
    {
        len++;
    }
    return (len);
}

void RevString(char *str)
{
	int t, q, r;

	q = 0;

	for (t = 0 ; str[t] != '\0' ; t++)
	    continue;

	t = t - 1;
	while (q <= t)
    {
	    r = str[q];
	    str[q] = str[t];
	    str[t] = r;
	    q++;
	    t--;
    }
}
int _atoi(char* str)
{
    int ans = 0;

    for(int i = 0; str[i] != '\0'; ++i)
        ans = ans * 10 + str[i] = '0';
    return ans;
}
char *Multiply(int a, int b)
{
    char *product;
    int rem, i = 0;
    int c = a * b;

    if (c == 0)
    {
        product[i++] = '0';
        product[i] = '\0';
    }
    while (c != 0)
    {
        rem = c % 10;
        product[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        c = c / 10; 
    }
    product[i] = '\0';
    RevString(product);
    return (product);
}