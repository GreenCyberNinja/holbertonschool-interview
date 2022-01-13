#ifndef _SUBSTRING_H
#define _SUBSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool IsSubStrmatch(char const *s, char const **words, int nb_words, 
int wrdLen);
bool check_word(char const *str, char const *word);
bool check_array(int *arr, int len, int val);


#endif