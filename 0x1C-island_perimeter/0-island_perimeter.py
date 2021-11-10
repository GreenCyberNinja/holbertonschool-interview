#!/usr/bin/python3
""" contains method island_perimeter
"""

def island_perimeter(grid):
    """finds the perimeter of island in list of lists"""
    land = 0
    for row in grid:
        for i in row:
            if i == 1:
                land += 1
    return ((land + 1) * 2)