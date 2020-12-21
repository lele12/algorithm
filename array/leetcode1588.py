#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1588.py
    @Author	:	fosaken
    @Time	:	2020/12/21 22:21:13
    @Abstract:

"""

from typing import List


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        """暴力解法"""
        # n = len(arr)
        # max_odd = n if n % 2 == 1 else n - 1
        # sum_ = 0
        # for l in range(1, max_odd+1, 2):
        #     for start in range(n-l+1):
        #         sum_ += sum(arr[start:start+l])
        # return sum_

        """优化了一下，以为挺好了，不过还是很垃圾"""
        n = len(arr)
        sum_list = [0]
        for num in arr:
            sum_list.append(sum_list[-1] + num)
        max_odd = n if n % 2 == 1 else n - 1
        sum_ = sum(arr)
        if max_odd < 3:
            return sum_
        for l in range(3, max_odd+1, 2):
            for start in range(n-l+1):
                sum_ += sum_list[start+l] - sum_list[start]
        return sum_

        # TODO:
        """计算出现次数的方法"""


def main():
    solution = Solution()
    arr = [1, 4, 2, 5, 3]
    result = solution.sumOddLengthSubarrays(arr)
    print(result)


if __name__ == "__main__":
    main()
