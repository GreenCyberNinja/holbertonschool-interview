#ifndef SLIDE_H
#define SLIDE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int Lslide(int *line, unsigned int starting_index, size_t size, unsigned int *farthest_slid);
int Rslide(int *line, unsigned int starting_index, size_t size, unsigned int *farthest_slid);

#endif /* SLIDE_H */
