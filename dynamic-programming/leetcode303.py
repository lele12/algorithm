#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode303
    @Author fosaken
    @Date   2020/12/14
    @Abstract:
"""

from typing import List


# my naive solution
class NumArray:
    def __init__(self, nums: List[int]):
        self.__nums = nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self.__nums[i:j+1])


class NumArray:
    def __init__(self, nums: List[int]):
        self._sums = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self._sums[i + 1] = self._sums[i] + nums[i]

    def sumRange(self, i: int, j: int) -> int:
        return self._sums[j + 1] - self._sums[i]

