#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode389
    @Author fosaken
    @Date   2020/12/18
    @Abstract:
        Address: https://leetcode-cn.com/problems/find-the-difference/submissions/
"""

# 因为题目中说都是小写字母，故可以用其ASCII码作为索引，使用列表来计数，


class Solution:
    # my naive solution
    def findTheDifference(self, s: str, t: str) -> str:
        dict_s = dict()
        for char in s:
            if char in dict_s:
                dict_s[char] += 1
            else:
                dict_s[char] = 1

        for char in t:
            if char not in dict_s:
                return char
            else:
                dict_s[char] -= 1
            if dict_s[char] < 0:
                return char

    def findTheDifference2(self, s: str, t: str) -> str:
        table = [0] * 26
        for char in s:
            table[ord(char) - ord('a')] += 1

        for char in t:
            idx = ord(char) - ord('a')
            table[idx] -= 1
            if table[idx] < 0:
                return char

