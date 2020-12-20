#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1389.py
    @Author	:	fosaken
    @Time	:	2020/12/20 18:10:55
    @Abstract:

"""

from typing import List


class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = list()
        for i in range(len(nums)):
            target.insert(index[i], nums[i])
        return target


