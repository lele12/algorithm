#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode53
    @Author fosaken
    @Date   2020/12/15
    @Abstract:
        最大子序和
        Address: https://leetcode-cn.com/problems/maximum-subarray/
"""

from typing import List


def maxSubArray(nums: List[int]) -> int:
    l = len(nums)
    s = 0
    max_s = float('-inf')
    for i in range(l):
        s += nums[i]
        max_s = max(max_s, s)
        if s < 0:
            s = 0
    return max_s
