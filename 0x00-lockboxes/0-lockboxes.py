#!/usr/bin/python3
"""checks if you can unlock all the boxes by process of elimination"""


def canUnlockAll(boxes):
    keys = [0]
    box = len(boxes) - 1
    while box != 0:
        for i in set(keys):
            for j in set(boxes[i]):
                if j not in set(keys):
                    keys.append(j)
        box -= 1
    if len(set(keys)) >= len(boxes):
        return True
    else:
        return False
