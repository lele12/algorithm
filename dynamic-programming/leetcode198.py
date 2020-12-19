#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode198
    @Author fosaken
    @Date   2020/12/17
    @Abstract:
        Address: https://leetcode-cn.com/problems/house-robber/
"""

from typing import List


class Solution:
    # 注意和746的区别
    def rob(self, nums: List[int]) -> int:
        l = len(nums)
        if not l:
            return 0
        if l == 1:
            return nums[0]
        elif l == 2:
            return max(nums[0], nums[1])
        dp = [0] * l
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = max(nums[0] + nums[2], nums[1])
        for i in range(3, l):
            dp[i] = max(dp[i-3] + nums[i], dp[i-2] + nums[i], dp[i-1])
        return max(dp[-1], dp[-2])


def main():
    solution = Solution()
    nums = [2, 1, 1, 2]
    result = solution.rob(nums)
    print(result)
    pass


if __name__ == '__main__':
    main()

