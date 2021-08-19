#!/usr/bin/python3
"""file for project Rain"""


def rain(walls):
    """calculates rain collected"""
    if walls is None:
        return (0)
    thud = 0
    smlstWl = 0
    rnwtr = 0
    space = 0
    for wall in walls:
        if wall != 0 and thud != 0:
            if wall < smlstWl:
                smlstWl = wall
            rnwtr += smlstWl * space
            space = 0
            thud = 0
            smlstWl = 0
        if wall != 0 and thud == 0:
            thud = wall
            if smlstWl == 0:
                smlstWl = thud
        if wall == 0 and thud != 0:
            space += 1
    return rnwtr
