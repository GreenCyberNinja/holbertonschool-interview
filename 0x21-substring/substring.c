#include "substring.h"

/**
 * find_substring - finds all the possible substrings
 * containing a list of words, within a given string
 * 
 * @s: the string to search through
 * @words: the array of words to search for
 * @nb_words: the number of words in the list
 * @n: holds the address  to store the number of words found
 * 
 * Return: an allocated array of indexes in s where the
 * where the words are found or NULL if none are found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *ans, wrdLen = 0, i;
    size_t strLen = 0;

	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	*n = 0;

	for (i = 0; s[i] != '\0'; i++)
		strLen++;
	for (i = 0; words[0][i] != '\0'; i++)
		wrdLen++;

	ans = malloc(sizeof(int) * strLen);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (IsSubStrmatch(s + i, words, nb_words, wrdLen))
		{
			ans[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(ans);
		return (NULL);
	}
	return (ans);
}

/**
 * IsSubStrmatch - checks if substring is a concatenation of words
 * @s: the string to search through
 * @words: the array of words to search for
 * @nb_words: the number of words in the list
 * @wordLen: the length the length in words
 * Return: True if full match, false if not
 */
bool IsSubStrmatch(char const *s, char const **words, int nb_words, int wrdLen)
{
	int *checked, check_Len = 0, i, j, in_array;
	bool match = true, found;

	checked = malloc(sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++)
		checked[i] = -1;

	for (i = 0; i < nb_words; i++)
	{
		found = false;
		for (j = 0; j < nb_words; j++)
		{
			in_array = check_array(checked, check_Len, j);
			if (!in_array && check_word((s + (i * wrdLen)), words[j]))
			{
				checked[check_Len] = j;
				check_Len++;
				found = true;
				break;
			}
		}
		if (found == false)
		{
			match = false;
			break;
		}
	}
	free(checked);
	return (match);
}

/**
 * check_word - checks word against string
 * @str: a substring to check
 * @word: words to chyeck against
 * Return: true if match, false if not
 */
bool check_word(char const *str, char const *word)
{
	int i = 0;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (false);
	}
	return (true);
}

/**
 * check_array - checks if ans is in array arr
 * @arr: an array of int to check
 * @len: length of arr
 * @ans: the value to check for
 * Return: true if val is in arr false if not
 */
bool check_array(int *arr, int len, int val)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == val)
			return (true);
	}
	return (false);
}
