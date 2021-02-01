#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode160.py
    @Author	:	fosaken
    @Time	:	2021/02/01 22:24:55
    @Abstract:

"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        len_a = 0
        cur_node = headA
        while cur_node:
            len_a += 1
            cur_node = cur_node.next
        len_b = 0
        cur_node = headB
        while cur_node:
            len_b += 1
            cur_node = cur_node.next
        
        if len_a > len_b:
            sub = len_a - len_b
            count = 0
            node_a = headA
            while count < sub:
                node_a = node_a.next
                count += 1
            return self.getIntersectionNodeImpl(node_a, headB)
        elif len_b > len_a:
            sub = len_b - len_a
            count = 0
            node_b = headB
            while count < sub:
                node_b = node_b.next
                count += 1
            return self.getIntersectionNodeImpl(headA, node_b)
        else:
            return self.getIntersectionNodeImpl(headA, headB)
    
    def getIntersectionNodeImpl(self, nodeA, nodeB):
        if not nodeA or not nodeB:
            return None
        else:
            while nodeA and nodeB:
                if nodeA == nodeB:
                    return nodeA
                else:
                    nodeA = nodeA.next
                    nodeB = nodeB.next
            return None
