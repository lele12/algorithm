#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @File	:	leetcode1700.py
    @Author	:	fosaken
    @Time	:	2020/12/29 22:05:39
    @Abstract:

"""

from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = 0
        while students and count < len(students):
            if students[0] == sandwiches[0]:
                count = 0
                students.pop(0)
                sandwiches.pop(0)
            else:
                head = students.pop(0)
                students.append(head)
                count += 1
        return len(students)