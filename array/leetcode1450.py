#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1450.py
    @Author	:	fosaken
    @Time	:	2020/12/22 21:13:05
    @Abstract:

"""

from typing import List


class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        num = 0
        for i in range(len(startTime)):
            if startTime[i] <= queryTime <= endTime[i]:
                num += 1
        return num
