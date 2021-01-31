#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1290.py
    @Author	:	fosaken
    @Time	:	2021/01/31 20:20:30
    @Abstract:

"""


class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        count = 0
        cur_node = head
        while cur_node is not None:
            count += 1
            cur_node = cur_node.next
        cur_node = head
        res = 0
        while cur_node is not None:
            res += cur_node.val * 2 ** (count - 1)
            count -= 1
            cur_node = cur_node.next
        return res

