#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode59.py
    @Author	:	fosaken
    @Time	:	2020/12/23 21:58:48
    @Abstract:

"""

from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        i, j = 0, -1
        pos = list()
        idx = 0
        bound_count = 0
        while idx < n**2:
            for bound in range(4):
                l = n - (bound_count + 1) // 2
                bound_count += 1
                sub_idx = 0
                if l <= 0:
                    break
                if bound == 0:
                    delta_i, delta_j = 0, 1
                elif bound == 1:
                    delta_i, delta_j = 1, 0
                elif bound == 2:
                    delta_i, delta_j = 0, -1
                else:
                    delta_i, delta_j = -1, 0
                while sub_idx < l:
                    i += delta_i
                    j += delta_j
                    pos.append((i, j))

                    idx += 1
                    sub_idx += 1
            if l == 0:
                break
        res = [[None] * n for _ in range(n)]
        for i in range(n**2):
            res[pos[i][0]][pos[i][1]] = i + 1
        return res


def print_mat(mat):
    for line in mat:
        print(line)


def main():
    solution = Solution()
    res = solution.generateMatrix(5)
    print_mat(res)
    pass


if __name__ == "__main__":
    main()
    pass
