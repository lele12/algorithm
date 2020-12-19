#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header	leetcode1431.py
    @Author	fosaken
    @Time	2020/12/19 17:53:50
    Abstract:
        Address: https://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies
"""

from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies = max(candies)
        result = [False] * len(candies)
        for idx, num in enumerate(candies):
            if num + extraCandies >= max_candies:
                result[idx] = True
        return result

