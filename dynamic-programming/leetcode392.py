#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode392
    @Author fosaken
    @Date   2020/12/16
    @Abstract:
        Address: https://leetcode-cn.com/problems/is-subsequence/submissions/
"""


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ls = len(s)
        lt = len(t)
        i = j = 0
        while i < ls and j < lt:
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        if i >= ls:
            return True
        else:
            return False

    def isSubsequenceDP(self, s: str, t: str) -> bool:
        ls = len(s)
        lt = len(t)
        dp = [[lt] * 26 for _ in range(lt + 1)]
        for _t in range(lt-1, -1, -1):
            # ============================ #
            # ======== C O P Y =========== #
            dp[_t] = dp[_t + 1].copy()
            # ============================ #
            dp[_t][ord(t[_t]) - 97] = _t
        _t = _s = 0
        while _t < lt and _s < ls:
            idx = dp[_t][ord(s[_s]) - 97]
            if idx >= lt:
                return False
            else:
                _t = idx + 1
                _s += 1
        if _s == ls:
            return True
        else:
            return False


def main():
    solution = Solution()
    s = "aaaaaa"
    t = "bbaaaa"
    print(solution.isSubsequenceDP(s, t))


if __name__ == '__main__':
    main()

