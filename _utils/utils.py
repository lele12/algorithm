#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @header utils.py
    @author fosaken
    @date   2020/12/12
    @abstract:
"""


import time
import functools


def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        res = func(*args, **kwargs)
        end = time.time()
        printError(f"Time used: {(end - start) * 1000:.4f} ms")
        return res
    return wrapper


def printError(msg, end="\n"):
    print(f"\033[0;31;31m{msg}\033[0m", end=end)


@timer
def testMyFunc(func, loop, *args, **kwargs):
    printError(func.__name__, end=":\t")
    assert 0 < loop < 999999
    res = None
    for i in range(loop):
        res = func(*args, **kwargs)
    return res
