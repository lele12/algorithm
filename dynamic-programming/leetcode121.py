#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode121
    @Author fosaken
    @Date   2020/12/14
    @Abstract:
"""

from typing import List


# my naive solution
def maxProfit0(prices: List[int]) -> int:
    l = len(prices)
    if l == 1:
        return 0
    elif l == 2:
        return max(0, prices[1] - prices[0])
    else:
        profile = 0
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                profile = max(profile, prices[j] - prices[i])
        return profile


# optimized solution
def maxProfit1(prices: List[int]) -> int:
    l = len(prices)
    if l <= 1:
        return 0

    min_p = max_p = prices[0]
    max_profile = 0

    for p in prices:
        if p < min_p:
            min_p = p
            max_p = min_p
        elif p > max_p:
            max_p = p
            max_profile = max(max_profile, max_p - min_p)
    return max_profile
