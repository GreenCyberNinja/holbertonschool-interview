#!/usr/bin/python3
""" contains method island_perimeter
"""

def island_perimeter(grid):
    """finds the perimeter of island in list of lists"""
    land = 0
    x = 0
    y = 0
    for row in grid:
        for i in row:
            if i == 1:
                land += 1
        if land > 1:
            x += land
            y += 1
            land = 0
        else:
            y += land
            land = 0

    return ((2*x) + (2*y))