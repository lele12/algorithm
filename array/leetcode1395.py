#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1395.py
    @Author	:	fosaken
    @Time	:	2020/12/20 17:56:41
    @Abstract:

"""

from typing import List


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        if n < 3:
            return 0
        count = 0
        i_less = i_more = k_less = k_more = 0
        for j in range(1, n-1):
            for i in range(j):
                if rating[i] > rating[j]:
                    i_more += 1
                elif rating[i] < rating[j]:
                    i_less += 1
            for k in range(j+1, n):
                if rating[k] > rating[j]:
                    k_more += 1
                elif rating[k] < rating[j]:
                    k_less += 1
            count += i_more*k_less + i_less*k_more
            i_less = i_more = k_less = k_more = 0
        return count


def main():
    rating = [2,5,3,4,1]
    solution = Solution()
    result = solution.numTeams(rating)
    print(result)


if __name__ == "__main__":
    main()
    pass
