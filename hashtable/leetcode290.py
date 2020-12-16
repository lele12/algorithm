#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @Header leetcode290
    @Author fosaken
    @Date   2020/12/16
    @Abstract:
        Address: https://leetcode-cn.com/problems/word-pattern/submissions/
"""


def wordPattern(pattern: str, s: str) -> bool:
    char_map = dict()
    words = s.split()
    if len(pattern) != len(words):
        return False
    flag = True
    for idx, char in enumerate(pattern):
        if char not in char_map:
            char_map[char] = words[idx]
        else:
            flag = char_map[char] == words[idx]
        print(flag)
        if not flag:
            return False
    if len(set(char_map.values())) == len(char_map):
        return True
    else:
        return False
