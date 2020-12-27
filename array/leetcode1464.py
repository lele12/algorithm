#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode1464.py
    @Author fosaken
    @Date   2020/12/25
    @Abstract:
"""

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_num = sec_max_num = 0
        max_idx = sec_idx = -1
        for idx, num in enumerate(nums):
            if num > max_num:
                max_num, max_idx = num, idx

        for idx, num in enumerate(nums):
            if num > sec_max_num and idx != max_idx:
                sec_max_num, sec_idx = num, idx
        return (nums[max_idx] - 1) * (nums[sec_idx] - 1)
