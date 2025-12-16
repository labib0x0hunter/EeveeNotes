# Array
---
# Topics
- insertion : Given a static array of n + 1 size, insert at index idx.
- deletion : Given a static array of n size, delete at index idx.
- reverse : Given a static array of n size, reverse using loop and two pointer. 
- two pointer
- merge : Given two static array, merge them. Given two sorted array, merge them and output array must be sorted.
- sort : Given a static array, sort them using bubble sort, quick sort and merge sort.
---

# Quiz
This quizs are from ChatGPT. I will try to add more real interview quizs.
---
```text
Q1. Given two sorted array.
    A = [1, 4, 7, 8, 10]
    B = [2, 3, 9]

    Constraints:
        - Don't use extra arrays
        - Don't use built-in sort
        - Final result must be sorted
        - Time complexity better than O((n + m) log(n + m))
    
    Task: Explain step-by-step how to merge them in place and give
        - Core idea
        - Pointer movement logic
        - Time Complexity
        - Edge cases that break naive solutions.

    Bonus Task:
        - If you use Gap Method, then explain how is the initial gap computed and how does it shrink.
```

```text
Q2. Given an array. 
    A = [1, 2, 3, 4, 5, 6, 7]
    You must reverse only the EVEN numbers in place, keeping ODD numbers fixed in position.

    Constraints:
        - O(n) time
        - O(1) space
        - No extra array

    Explain:
        - Pointer initialization
        - Pointer movement rules
        - Termination condition
```

```text
Q3. Given an array, detect if it is sorted in:
    - strictly ascending
    - strictly descending
    - not sorted

    Constraints:
        - One pass
        - No sorting
        - Handle duplicates correctly

    Explain the flags / invariants
```

```text
Q4. You are given an array of distinct integers.
    A = [4, 5, 6, 7, 1, 2, 3]
    This is a rotation of a strictly ascending sorted array.

    Task: In one pass, determine whether the array is:
        - rotated sorted ascending
        - strictly sorted ascending (no rotation)
        - not rotated sorted

    Constraints:
        - O(n) time
        - O(1) space
        - No sorting
        - No extra array

    Explain
        - What invariant you track
        - What condition invalidates the array
        - How you distinguish pure sorted vs rotated sorted
```