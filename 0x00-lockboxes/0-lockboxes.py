#!/usr/bin/python3
def canUnlockAll(boxes):
    for i in range(boxes):
        check = 0
        for j in range(boxes[i]):
            if j == i + 1:
                check = 1
                break
        if check == 0:
            return (false)
    return (true)
