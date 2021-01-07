#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode120.py
    @Author	:	fosaken
    @Time	:	2021/01/07 23:19:30
    @Abstract:

"""

from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = triangle.copy()
        depth = len(triangle)
        width = len(triangle[-1])
        for layer_idx in range(depth-1, -1, -1):
            if layer_idx == depth - 1:
                continue
            else:
                for idx in range(len(triangle[layer_idx])):
                    dp[layer_idx][idx] = min(dp[layer_idx+1][idx], dp[layer_idx+1][idx+1]) + dp[layer_idx][idx]
        return dp[0][0]
