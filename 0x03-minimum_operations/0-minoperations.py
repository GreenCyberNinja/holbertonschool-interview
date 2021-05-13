#!/usr/bin/python3
"""
loops through until lowest factor then copies and pastes it
"""


def minOperations(n):
    """I think this is efficient? famous last words"""
    if n <= 1:
        return 0
    ans = 0
    h = 1
    copa = 1
    while h != n:
        if n % h == 0:
            copa = h
            ans += 1
        h = h + copa
        ans += 1
    return ans
