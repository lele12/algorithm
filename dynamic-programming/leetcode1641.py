#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode1641
    @Author fosaken
    @Date   2020/12/17
    @Abstract:
        Address: https://leetcode-cn.com/problems/count-sorted-vowel-strings/
"""


class Solution:
    def countVowelStrings(self, n: int) -> int:
        # if not n:
        #     return 0
        dp = [[1] * 5 for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, 5):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[n][4]


def main():
    n = 4
    solution = Solution()
    result = solution.countVowelStrings(n)
    print(result)
    # TODO: why solution.countVowelStrings(0) == 1 ?
    pass


if __name__ == '__main__':
    main()
