#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1365.py
    @Author	:	fosken
    @Time	:	2020/12/20 18:39:28
    @Abstract:

"""

from typing import List

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        # 暴力法
        # result = list()
        # n = len(nums)
        # for i in range(n):
        #     count = 0
        #     for j in range(n):
        #         if j == i:
        #             continue
        #         if nums[j] < nums[i]:
        #             count += 1
        #     result.append(count)
        # return result
        counter = [0] * 101
        for num in nums:
            counter[num] += 1
        for idx in range(1, len(counter)):
            counter[idx] = counter[idx] + counter[idx-1]
        result = list()
        for num in nums:
            if num == 0:
                result.append(0)
            else:
                result.append(counter[num-1])
        return result
