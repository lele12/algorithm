#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode70.py
    @Author fosaken
    @Date   2020/12/12
    @Abstract:
        Address: https://leetcode-cn.com/problems/climbing-stairs
        Speed: climbStairs1 > climbStairs3 > climbStairs2 >> climbStairs0
"""

from _utils import testMyFunc


# my naive solution(Don't try it)
def climbStairs0(n: int) -> int:
    if n < 3:
        return n
    return climbStairs0(n - 1) + climbStairs0(n - 2)


# my naive dp solution1
def climbStairs1(n: int) -> int:
    if n < 3:
        return n
    dp = [0] * n
    dp[0], dp[1] = 1, 2
    for i in range(2, n):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[-1]


# my naive dp solution2
def climbStairs2(n: int) -> int:
    if n < 3:
        return n
    dp = [0] * 3
    dp[0], dp[1] = 1, 2
    for i in range(2, n):
        dp[2] = dp[0] + dp[1]
        dp[0], dp[1] = dp[1], dp[2]
    return dp[-1]


# my naive dp solution3
def climbStairs3(n: int) -> int:
    if n < 3:
        return n
    dp = [0] * 2
    dp[0], dp[1] = 1, 2
    for i in range(2, n):
        dp.append(dp[0] + dp[1])
        dp.pop(0)
    return dp[-1]


def climbStairs4(n: int) -> int:
    # TODO: O(log(n))?
    return 0


def main():
    num_stairs = 44
    # too slow
    # testMyFunc(climbStairs0, 1000, num_stairs)
    testMyFunc(climbStairs1, 1000, num_stairs)
    testMyFunc(climbStairs2, 1000, num_stairs)
    testMyFunc(climbStairs3, 1000, num_stairs)


if __name__ == '__main__':
    main()
