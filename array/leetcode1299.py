#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1299.py
    @Author	:	fosaken
    @Time	:	2020/12/24 22:04:55
    @Abstract:

"""

from typing import List


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        l = len(arr)
        arr_bak = arr.copy()
        max_num = -1
        for idx in range(l-1, -1, -1):
            if idx == l-1:
                max_num = -1
            else:
                max_num = max(arr_bak[idx+1], max_num)
            arr[idx] = max_num
        return arr

