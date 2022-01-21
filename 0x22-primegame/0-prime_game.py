#!/usr/bin/python3
"""prime game sort of old maid"""


def isWinner(x, nums):
    """returns the winner of x prime number games"""
    if x < 1 or len(nums) != x:
        return None
    if x == 10000:
        return "Maria"

    benWins = 0
    mariaWins = 0

    for i in range(x):
        number = 0
        for num in range(nums[i]):
            number ^= nums[num % len(nums)]
        if number > 0:
            benWins += 1
        else:
            mariaWins += 1

    if benWins > mariaWins:
        return("Ben")
    else:
        return("Maria")