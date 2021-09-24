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

    if (argc != 3 || IsNum(argv[1]) != 0 || IsNum(argv[2]) != 0)
    {
        _puts("Error\n");
        exit(98);
    }
    ans = Multiply(argv[1], argv[2]);
    _puts(ans);
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
    int i;

    for(i = 0; str[i] != '\0'; ++i)
        ans = ans * 10 + str[i] - '0';
    return ans;
}
char *Multiply(char *a, char *b)
{
 	int l1 = _len(a);
	int l2 = _len(b);
	int i, j, num1, num2, infrnt1 = 0, infrnt2 = 0;
	int carried = 0, sum = 0;
	char *product = malloc(sizeof(char) * (l1 + l2));

	for (i = 0; i < (l1 + l2); i++)
	{
		product[i] = '0';
	}
	for (i = l1 - 1; i >= 0; i--)
	{
		carried = 0;
		num1 = a[i] - '0';
		infrnt2 = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			num2 = b[j] - '0';
			if (product[infrnt1 + infrnt2] > 9)
				product[infrnt1 + infrnt2] -= '0';
			sum = num1 * num2 + product[infrnt1 + infrnt2] + carried;
			carried = sum / 10;
			product[infrnt1 + infrnt2] = (sum % 10) + '0';
			infrnt2++;
		}
		if (carried > 0)
		{
			product[infrnt1 + infrnt2] += carried;
		}
		infrnt1++;
	}
    RevString(product);
    return (product);
}