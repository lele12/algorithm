#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1486.py
    @Author	:	fosaken
    @Time	:	2020/12/20 17:24:29
    @Abstract:
        Address: https://leetcode-cn.com/problems/xor-operation-in-an-array/
"""


class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        num = start + 2 * 0
        for i in range(1, n):
            num = num ^ (start + 2 * i)
        return num
