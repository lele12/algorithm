#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode1
    @Author fosaken
    @Date   2020/12/19
    @Abstract:
        Address: https://leetcode-cn.com/problems/two-sum/
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = len(nums)
        for i in range(l):
            for j in range(i + 1, l):
                if nums[i] + nums[j] == target:
                    return [i, j]

