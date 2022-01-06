#!/usr/bin/python3
"""returns a pascal triangle of n height"""


def pascal_triangle(n):
    """creates and returns a list of list representing a pascal triangle"""
    ans = []
    if n <= 0:
        return ans

    for line in range(1, n + 1):
        C = 1
        row = []
        for i in range(1, line + 1):
            row.append(C)
            C = int(C * (line - i) / i)
        ans.append(row)

    return ans
