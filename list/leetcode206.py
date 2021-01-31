#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode206.py
    @Author	:	fosaken
    @Time	:	2021/01/31 20:41:05
    @Abstract:

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur_node = head
        last_head = None
        while cur_node is not None:
            cur_head = ListNode()
            cur_head.val = cur_node.val
            cur_head.next = last_head
            last_head = cur_head
            cur_node = cur_node.next
        return last_head