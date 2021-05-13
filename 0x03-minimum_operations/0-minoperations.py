#!/usr/bin/python3

def minOperations(n):
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