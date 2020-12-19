#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode48
    @Author fosaken
    @Date   2020/12/19
    @Abstract:
        旋转图像
        Address: https://leetcode-cn.com/problems/rotate-image/
"""

from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n < 2:
            return
        for i in range(n//2):
            for j in range(i, n-1-i):
                matrix[i][j], matrix[j][n-1-i], matrix[n-1-i][n-1-j], matrix[n-1-j][i] =  matrix[n-1-j][i], matrix[i][j], matrix[j][n-1-i], matrix[n-1-i][n-1-j]
        return


def main():
    matrix = [
  [1,2,3,4],
  [5,6,7,8],
  [9,10,11,12],
  [13, 14, 15, 16]
  ]
    solution = Solution()
    solution.rotate(matrix)
    print(matrix)


if __name__ == "__main__":
    main()
