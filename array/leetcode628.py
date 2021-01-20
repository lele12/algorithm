#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode628.py
    @Author	:	fosaken
    @Time	:	2021/01/20 22:38:08
    @Abstract:

"""

from typing import List


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 3:
            return nums[0] * nums[1] * nums[2]
        self.top3 = [-1001] * 3
        self.bottom2 = [1001] * 2
        for num in nums:
            self.update(num)
        return max(
            self.top3[0] * self.top3[1] * self.top3[2],
            self.top3[0] * self.bottom2[0] * self.bottom2[1]
        )
    
    def update(self, num):
        if num > self.top3[0]:
            self.top3.pop()
            self.top3.insert(0, num)
        elif num > self.top3[1]:
            self.top3.pop()
            self.top3.insert(1, num)
        elif num > self.top3[2]:
            self.top3.pop()
            self.top3.insert(2, num)
        if num < self.bottom2[0]:
            self.bottom2[0], self.bottom2[1] = num, self.bottom2[0]
        elif num < self.bottom2[1]:
            self.bottom2[1] = num


def main():
    solution = Solution()
    print(solution.maximumProduct([1, 2, 3, -4]))
    pass


if __name__ == "__main__":
    main()
    pass