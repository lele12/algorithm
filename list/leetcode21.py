#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode21.py
    @Author	:	fosaken
    @Time	:	2021/01/31 21:13:54
    @Abstract:

"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # TODO:(optimize)
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 and not l2:
            return None
        elif l1 and not l2:
            return l1
        elif not l1 and l2:
            return l2
        else:
            pass
        cur_n1 = l1
        cur_n2 = l2
        head = ListNode()
        cur_node = head
        while cur_n1 and cur_n2:
            if cur_n1.val < cur_n2.val:
                cur_node.val = cur_n1.val
                cur_n1 = cur_n1.next
            else:
                cur_node.val = cur_n2.val
                cur_n2 = cur_n2.next
            new_node = ListNode()
            cur_node.next = new_node
            cur_node = cur_node.next
        if cur_n1:
            cur_node.val = cur_n1.val
            cur_node.next = cur_n1.next
        else:
            cur_node.val = cur_n2.val
            cur_node.next = cur_n2.next
        return head
