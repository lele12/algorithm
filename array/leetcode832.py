#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode832.py
    @Author	:	fosaken
    @Time	:	2021/01/06 21:58:17
    @Abstract:

"""

from typing import List


class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        n = len(A)
        flag = n % 2 == 1
        for i in range(n):
            for j in range(n//2):
                A[i][j], A[i][n-1-j] = (1 - A[i][n-1-j]), (1 - A[i][j])
            if flag:
                A[i][n//2] = 1 - A[i][n//2]
        return A
