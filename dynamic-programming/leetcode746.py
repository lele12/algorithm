#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode746
    @Author fosaken
    @Date   2020/12/15
    @Abstract:
"""

from typing import List


def minCostClimbingStairs(cost: List[int]) -> int:
    # TODO: need comment
    l = len(cost)
    dp = [0] * 3
    dp[0], dp[1] = cost[0], cost[1]
    if l == 2:
        return min(cost)
    for i in range(2, l):
        dp[2] = min(dp[0], dp[1]) + cost[i]
        dp[0], dp[1] = dp[1], dp[2]
    return min(dp[0], dp[2])
