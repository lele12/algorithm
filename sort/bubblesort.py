#!/usr/bin/env python
# -*- coding:utf-8 -*-
# Author:我是想说三

import random


def bubble_sort(nums):
    length = len(nums)
    if length < 2:
        return
    for i in range(length - 1):
        max_idx = 0
        for j in range(1, length - i):
            if nums[j] < nums[max_idx]:
                nums[j], nums[max_idx] = nums[max_idx], nums[j]
                max_idx = j
            else:
                max_idx = j


def print_nums(nums):
    print(f"nums: {' '.join(map(str, nums))}")


def test_bubble_sort():
    nums = []
    print_nums(nums)
    bubble_sort(nums)
    print_nums(nums)
    print()

    nums = [0]
    print_nums(nums)
    bubble_sort(nums)
    print_nums(nums)
    print()

    nums = [1, 0]
    print_nums(nums)
    bubble_sort(nums)
    print_nums(nums)
    print()

    nums = list(range(10))
    random.shuffle(nums)
    print_nums(nums)
    bubble_sort(nums)
    print_nums(nums)
    pass


if __name__ == '__main__':
    test_bubble_sort()
