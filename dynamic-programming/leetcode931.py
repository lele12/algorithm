#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode931.py
    @Author	:	fosaken
    @Time	:	2021/01/07 23:48:31
    @Abstract:

"""

from typing import List


class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        depth = len(A)
        dp = A.copy()
        for layer_idx in range(depth - 1, -1, -1):
            if layer_idx == depth - 1:
                continue
            for idx in range(depth):
                if idx == 0:
                    dp[layer_idx][idx] = min(dp[layer_idx + 1][idx], dp[layer_idx + 1][idx + 1]) + dp[layer_idx][idx]
                elif idx == depth - 1:
                    dp[layer_idx][idx] = min(dp[layer_idx + 1][idx - 1], dp[layer_idx + 1][idx]) + dp[layer_idx][idx]
                else:
                    dp[layer_idx][idx] = min(dp[layer_idx + 1][idx - 1], dp[layer_idx + 1][idx], dp[layer_idx + 1][idx + 1]) + dp[layer_idx][idx]
        return min(dp[0])
