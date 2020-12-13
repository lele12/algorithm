#!/usr/bin/env python
# -*- coding:utf-8 -*-
"""
    @header leetcode217.py
    @author fosaken
    @date   2020/12/13
    @abstract:
        Address: https://leetcode-cn.com/problems/contains-duplicate
"""

from typing import List


def containsDuplicate(nums: List[int]) -> bool:
    nums_set = set()
    for num in nums:
        if num not in nums_set:
            nums_set.add(num)
        else:
            return True
    return False


def main():
    print(containsDuplicate([]))
    print(containsDuplicate([1]))
    print(containsDuplicate([1, 2, 3, 4]))
    print(containsDuplicate([1, 2, 1, 1]))


if __name__ == '__main__':
    main()
