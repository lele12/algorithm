#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode70.py
    @Author fosaken
    @Date   2020/12/12
    @Abstract:
        Address: https://leetcode-cn.com/problems/climbing-stairs
"""

from _utils import testMyFunc


# my naive solution(Don't try it)
def climbStairs0(n: int) -> int:
    if n < 3:
        return n
    return climbStairs0(n - 1) + climbStairs0(n - 2)


# my naive dp solution
def climbStairs1(n: int) -> int:
    if n < 3:
        return n
    dp = [0] * n
    dp[0], dp[1] = 1, 2
    for i in range(2, n):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[-1]


def main():
    num_stairs = 15
    testMyFunc(climbStairs0, 1000, num_stairs)
    testMyFunc(climbStairs1, 1000, num_stairs)


if __name__ == '__main__':
    main()
