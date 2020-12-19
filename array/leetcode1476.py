#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode1476
    @Author fosaken
    @Date   2020/12/19
    @Abstract:
        Address: https://leetcode-cn.com/problems/subrectangle-queries/
"""

class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.rect = rectangle.copy()
        self.h = len(self.rect)
        if self.h > 0:
            self.w = len(self.rect[0])
        else:
            self.w = 0


    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        for i in range(min(row1, self.h), min(row2+1, self.h)):
            for j in range(min(col1, self.w), min(col2+1, self.w)):
                self.rect[i][j] = newValue


    def getValue(self, row: int, col: int) -> int:
        if 0 <= row < self.h and 0 <= col < self.w:
            return self.rect[row][col]
        else:
            return None
