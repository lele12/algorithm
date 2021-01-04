#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode509.py
    @Author	:	fosaken
    @Time	:	2021/01/04 22:29:59
    @Abstract:

"""


class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        n_2, n_1 = 0, 1
        for i in range(1, n):
            n_0 = n_2 + n_1
            n_2, n_1 = n_1, n_0
        return n_0
