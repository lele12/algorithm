#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1295.py
    @Author	:	fosaken
    @Time	:	2020/12/20 21:56:24
    @Abstract:

"""

from typing import List


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result += len(str(num)) % 2 == 0
        return result
