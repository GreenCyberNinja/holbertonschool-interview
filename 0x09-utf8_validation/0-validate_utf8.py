#!/usr/bin/python3
"""Module checks if valid UTF8"""


def validUTF8(data):
    """Determines if valid UTF-8 encoding via bitwise operations"""
    NumBytes = 0

    bitop1 = 1 << 7
    bitop2 = 1 << 6

    for num in data:
        bitop = 1 << 7
        if NumBytes == 0:
            while bitop & num:
                NumBytes += 1
                bitop = bitop >> 1
            if NumBytes == 0:
                continue
            if NumBytes == 1 or NumBytes > 4:
                return False
        else:
            if not (num & bitop1 and not (num & bitop2)):
                return False
        NumBytes -= 1
    return NumBytes == 0
    