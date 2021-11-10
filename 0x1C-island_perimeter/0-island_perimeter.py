#!/usr/bin/python3
""" contains method island_perimeter
"""

def island_perimeter(grid):
    """finds the perimeter of island in list of lists"""

    count = 0
    land = False
    x = {}
    y = 0
    for row in grid:
        for i in row:
            count += 1
            if i == 1:
                land = True
                if count not in x:
                    x[count] = 1
        if land == True:
            y += 1
            land = False
        count = 0
    return ((2*len(x)) + (2*y))