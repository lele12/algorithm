#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header	leetcode1480.py
    @Author	fosaken
    @Time	2020/12/19 16:37:50
    Abstract:
        Address: https://leetcode-cn.com/problems/running-sum-of-1d-array/
"""

from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        dynamic_sum = [0]
        for num in nums:
            dynamic_sum.append(dynamic_sum[-1] + num)
        dynamic_sum.pop(0)
        return dynamic_sum

