#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1351.py
    @Author	:	fosaken
    @Time	:	2021/01/06 21:39:08
    @Abstract:

"""

from typing import List


class Solution:
    def countNegatives_0(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        neg_i, neg_j = m, n
        count = 0
        for i in range(m):
            for j in range(n):
                if i >= neg_i and j >= neg_j:
                    count += 1
                    continue
                if grid[i][j] < 0:
                    count += 1
                    neg_i, neg_j = i, j
        return count
    
    def countNegatives_1(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        neg_j = n
        count = 0
        for i in range(m):
            j = 0
            while j < neg_j:
                if grid[i][j] < 0:
                    neg_j = j
                    break
                j += 1
            count += (n - neg_j)
        return count 

