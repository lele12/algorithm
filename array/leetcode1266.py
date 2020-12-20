#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1266.py
    @Author	:	fosken
    @Time	:	2020/12/20 21:37:40
    @Abstract:

"""

from typing import List


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        steps = 0
        for i in range(1, n):
            delta_x = abs(points[i][0] - points[i-1][0])
            delta_y = abs(points[i][1] - points[i-1][1])
            steps += max(delta_x, delta_y)
        return steps
