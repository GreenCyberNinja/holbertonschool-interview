#!/usr/bin/python3
"""Log parsing for status codes and files"""
import sys
import re


def codePrint(totalBytes, allCodes):
    """prints Allcodes if there are any"""
    print("File size: {:d}".format(totalBytes))
    for key in allCodes.keys():
        if (allCodes[key]):
            print("{:s}: {:d}".format(key, allCodes[key]))


if __name__ == "__main__":

    form = ".+ .+ \d+"
    pat = re.compile(form)
    totalBytes = 0
    allCodes = {"200": 0, "301": 0, "400": 0,
                "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}
    try:
        loop = 10
        for ln in sys.stdin:
            if (pat.match(ln)):
                v = ln.split('"')[2].split()
                totalBytes += int(v[1])
                if v[0] in allCodes.keys():
                    allCodes[v[0]] += 1
                loop -= 1
                if loop < 1:
                    codePrint(totalBytes, allCodes)
                    loop = 10
        codePrint(totalBytes, allCodes)
    except KeyboardInterrupt:
        codePrint(totalBytes, allCodes)
        sys.exit(0)
