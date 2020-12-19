#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header	leetcode1512.py
    @Author	fosaken
    @Time	2020/12/19 17:48:03
    Abstract:
        Address: https://leetcode-cn.com/problems/number-of-good-pairs
"""

from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        nip = 0
        l = len(nums)
        if l < 2:
            return nip
        for i in range(l-1):
            for j in range(i+1, l):
                if nums[i] == nums[j]:
                    nip += 1
        return nip
