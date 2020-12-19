#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header	leetcode64.py
    @Author	fosaken
    @Time	2020/12/19 16:47:00
    Abstract:
"""

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        h = len(grid)
        w = len(grid[0]) if h > 0 else 0
        if not h or not w:
            return 0
        dp = [[0] * w for _ in range(h)]
        dp[0][0] = grid[0][0]
        for i in range(1, h):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for i in range(1, w):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for i in range(1, h):
            for j in range(1, w):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[-1][-1]


def main():
    grid = [[1,4,8,6,2,2,1,7],[4,7,3,1,4,5,5,1],[8,8,2,1,1,8,0,1],[8,9,2,9,8,0,8,9],[5,7,5,7,1,8,5,5],[7,0,9,4,5,6,5,6],[4,9,9,7,9,1,9,0]]
    solution = Solution()
    result = solution.minPathSum(grid)
    print(result)


if __name__ == "__main__":
    main()
