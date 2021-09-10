#!/usr/bin/python3
"""queries reddit api for count of works in hot list usingt recursion"""
import requests


def count_words(subreddit, word_list, Nxtpge=None, count={}):
    """Count all keywords in word_list of subreddit"""
    if Nxtpge is None:
        subredURL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        subredURL = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, Nxtpge)
    subredreq = requests.get(subredURL,
                                 headers={"user-agent": "user"},
                                 allow_redirects=False)
    try:
        data = subredreq.json().get("data")
    except:
        return
    for wrd in word_list:
        wrd = wrd.lower()
        if wrd not in count.keys():
            count[wrd] = 0
    chldrn = data.get("children")
    for chld in chldrn:
        ttl = (chld.get("data").get("title").lower())
        ttl = ttl.split(' ')
        for wrd in word_list:
            wrd = wrd.lower()
            count[wrd] += ttl.count(wrd)
    Nxtpge = data.get("after")
    if Nxtpge is not None:
        return count_words(subreddit, word_list, Nxtpge, count)
    else:
        sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for i in sorted_subs:
            if i[1] != 0:
                print(i[0] + ": " + str(i[1]))
