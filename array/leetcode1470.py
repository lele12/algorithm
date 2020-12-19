#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header	leetcode1470.py
    @Author	fosaken
    @Time	2020/12/19 17:42:08
    Abstract:
        Address: https://leetcode-cn.com/problems/shuffle-the-array/
"""

from typint import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        new_nums = list()
        n = len(nums) // 2
        for i in range(n):
            new_nums.append(nums[i])
            new_nums.append(nums[i+n])
        return new_nums
