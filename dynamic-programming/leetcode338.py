#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode338.py
    @Author	:	fosaken
    @Time	:	2021/01/14 22:52:37
    @Abstract:

"""

from typing import List


class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]
        if num > 0:
            dp.append(1)
        for i in range(2, num+1):
            q, r = divmod(i, 2)
            dp.append(dp[q] + dp[r])
        return dp
