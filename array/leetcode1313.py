#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1313.py
    @Author	:	fosaken
    @Time	:	2020/12/20 18:14:39
    @Abstract:

"""

from typing import List 


class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = list()
        n = len(nums) // 2
        for i in range(n):
            result += [nums[2 * i + 1]] * nums[2 * i]
        return result
