#!/usr/bin/python3
def canUnlockAll(boxes):
    for i in range(len(boxes)- 1):
        check = 0
        print("loop")
        for j in range(len(boxes[i])):
            if boxes[i][j] == i + 1:
                check = 1
                break
        if check == 0:
            return False
    return True
