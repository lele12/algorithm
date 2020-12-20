#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1572.py
    @Author	:	fosaken
    @Time	:	2020/12/20 22:00:53
    @Abstract:

"""

from typing import List


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sum_ = 0
        n = len(mat)
        for i in range(n):
            sum_ += mat[i][i] + mat[i][n-1-i]
        if n % 2 == 1:
            sum_ -= mat[(n-1)//2][(n-1)//2]
        return sum_
