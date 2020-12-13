#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode62
    @Author fosaken
    @Date   2020/12/13
    @Abstract:
"""


def uniquePaths(m: int, n: int) -> int:
    if m == 0 or n == 0:
        return 1
    dp = [[1] * n] * m

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    return dp[m - 1][n - 1]
