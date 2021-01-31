#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode876.py
    @Author	:	fosaken
    @Time	:	2021/01/31 20:57:13
    @Abstract:

"""

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        while fast is not None:
            fast = fast.next
            if fast is None:
                return slow
            else:
                slow = slow.next
            fast = fast.next
        
        return slow
