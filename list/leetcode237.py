#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode237.py
    @Author	:	fosaken
    @Time	:	2021/01/31 20:14:30
    @Abstract:

"""

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        post = node.next
        node.val = post.val
        node.next = post.next
