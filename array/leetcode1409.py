#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1409.py
    @Author	:	fosaken
    @Time	:	2020/12/22 21:08:17
    @Abstract:

"""

from typing import List


class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = list(range(1, m+1))
        res = list()
        for q in queries:
            idx = p.index(q)
            res.append(idx)
            p.pop(idx)
            p.insert(0, q)
        return res

