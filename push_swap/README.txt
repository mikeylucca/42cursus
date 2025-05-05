# Push Swap

## Overview

The **Push Swap** program is a sorting algorithm designed to sort a stack of integers using two stacks (`stack_a` and `stack_b`) and a limited set of operations. The goal is to sort the numbers in ascending order with the least number of operations possible. This project is part of the 42 curriculum and focuses on algorithm optimization and efficient memory management.

---

## How It Works

### Input
The program takes a list of integers as input, either as:
- A single string of space-separated numbers (e.g., `"3 2 1"`)
- Multiple arguments (e.g., `3 2 1`)

### Output
The program outputs the sequence of operations required to sort the stack.

### Operations
The program uses the following operations:
- `sa`: Swap the first two elements of `stack_a`.
- `sb`: Swap the first two elements of `stack_b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element of `stack_b` onto `stack_a`.
- `pb`: Push the top element of `stack_a` onto `stack_b`.
- `ra`: Rotate `stack_a` (shift all elements up, first becomes last).
- `rb`: Rotate `stack_b` (shift all elements up, first becomes last).
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate `stack_a` (shift all elements down, last becomes first).
- `rrb`: Reverse rotate `stack_b` (shift all elements down, last becomes first).
- `rrr`: Perform `rra` and `rrb` simultaneously.

---

## Algorithm Explanation

### Step-by-Step Process

1. **Input Parsing**
   - If the input is a single string, it is split into individual numbers using `split_args`.
   - The program checks for errors (e.g., duplicates, invalid characters) using `ft_handle_errors`.

2. **Stack Initialization**
   - Two stacks (`stack_a` and `stack_b`) are created using `create_tab`.
   - `stack_a` is initialized with the input numbers, while `stack_b` starts empty.

3. **Sorting Decision**
   - The program determines the sorting strategy based on the number of elements:
     - **2 Elements**: If unsorted, swap them using `sa`.
     - **3 Elements**: Use `resolve_three` to sort the three numbers.
     - **More Elements**: Use `resolve_stack` to sort the stack using advanced algorithms (e.g., quicksort or radix sort).

4. **Sorting Execution**
   - The chosen sorting function performs the necessary operations to sort `stack_a` while using `stack_b` as a helper stack.

5. **Memory Cleanup**
   - All allocated memory (e.g., stacks, split arguments) is freed using `ft_free`.

---

## Example Walkthrough

### Example 1: Sorting 3 Numbers
Input: `3 2 1`

1. **Initialization**
   - `stack_a`: `[3, 2, 1]`
   - `stack_b`: `[]`

2. **Sorting**
   - The program detects 3 elements and calls `resolve_three`.
   - Operations:
     - `sa`: Swap the first two elements → `[2, 3, 1]`
     - `rra`: Reverse rotate → `[1, 2, 3]`

3. **Output**

-------------------------------------------------------------------------------------

##### Key Concepts
##### Stack Representation:

Each stack is represented as an array of t_elem structures, which store the number (num), its index (index), and whether the position is filled (filled).
Operations:

The algorithm uses operations like sa, pb, ra, etc., to manipulate the stacks. Each operation is chosen based on the current state of the stacks and the target position of elements.
Median and Thresholds:

The algorithm often calculates the median of the stack to divide elements into smaller groups for sorting.
Thresholds are used to determine whether an element should be moved to stack_b or kept in stack_a.
Cost Calculation:

The algorithm calculates the "cost" of moving an element to its correct position. This cost is based on the number of operations required to move the element.
Step-by-Step Movement Calculation

*** 1. Finding the Median
The median is calculated using the get_median function:

The algorithm iterates through the stack and identifies the element that is approximately in the middle of the sorted order.
This median is used to split the stack into smaller groups for sorting.

*** 2. Pushing Elements to stack_b
The resolve_stack function pushes elements from stack_a to stack_b:

Elements smaller than the median are pushed to stack_b using the pb operation.
If an element in stack_b is larger than the median, it may be rotated (rb) to optimize future operations.

*** 3. Calculating the Cost of Moving Elements
The cost of moving an element is calculated using functions like get_op_for_topplace and get_op_for_gplace:

get_op_for_topplace:

Calculates the number of operations needed to bring an element to the top of the stack.
If the element is closer to the top, fewer operations are needed.
If the element is closer to the bottom, reverse rotations (rra or rrb) are used.
get_op_for_gplace:

Calculates the total cost of moving an element from stack_a to its correct position in stack_b.
This includes the cost of bringing the element to the top of stack_a and finding its correct position in stack_b.


*** 4. Resolving Coherences
The resolve_coherences function ensures that elements in both stacks are aligned for efficient sorting:

If both stacks need to be rotated in the same direction, the algorithm performs a double rotation (rr or rrr) to minimize operations.


*** 5. Sorting Small Groups
For small groups (e.g., 3 elements), the resolve_three function is used:

The function checks the positions of the minimum and maximum elements and performs swaps (sa) or rotations (ra, rra) to sort the group.


*** 6. Final Sorting
Once all elements are in their correct positions, the algorithm performs final rotations to align the smallest element at the top of stack_a:

The r_top function calculates whether to use ra or rra based on the position of the smallest element.
Example Calculation
Input: 4 2 5 1 3
Initial State:

stack_a: [4, 2, 5, 1, 3]
stack_b: []
Median Calculation:

Median = 3
Push to stack_b:

Push 4 → stack_a: [2, 5, 1, 3], stack_b: [4]
Push 2 → stack_a: [5, 1, 3], stack_b: [2, 4]
Sort Remaining in stack_a:

Sort [5, 1, 3] using resolve_three.
Merge Back to stack_a:

Push elements from stack_b back to stack_a in sorted order.
Final Alignment:

Rotate stack_a to align the smallest element at the top.



--------------------------------------------------------------------

### Coherence in Detail:

When moving an element from stack_a to its correct position in stack_b, the algorithm calculates the number of rotations needed for both stacks. If both stacks need to rotate in the same direction (either up or down), the algorithm can perform a double rotation (rr for up or rrr for down) to reduce the total number of operations.

The coherence value is the overlap between the rotations required for stack_a and stack_b. This overlap is used to adjust the total cost of the operation.

Coherence Calculation
The coherence is calculated in the function get_coherences:

int get_coherences(t_elem *stack_a, t_elem *stack_b, int index);

It determines how many rotations in stack_a and stack_b can be performed simultaneously.
If the rotations are in the same direction, the coherence value is positive.
If the rotations are in opposite directions, the coherence value is negative (indicating inefficiency).

## Example of Coherence

Scenario:
stack_a requires 3 rotations (ra) to bring the target element to the top.
stack_b requires 2 rotations (rb) to position the target element correctly.

## Coherence:

Since both stacks rotate in the same direction (ra and rb), the coherence is min(3, 2) = 2.
The algorithm can perform 2 double rotations (rr), reducing the total cost.


Adjusted Cost:

Without coherence: 3 (ra) + 2 (rb) = 5 operations.
With coherence: 3 + 2 - 2 (coherence) = 3 operations.

## Negative Coherence

If stack_a requires rotations in one direction (ra) and stack_b requires rotations in the opposite direction (rrb), the coherence is negative. This indicates that the stacks are not aligned, and the algorithm must perform separate rotations for each stack.

## How Coherence is Used

The coherence value is applied in the function resolve_coherences:

If the coherence is positive, the algorithm performs rr or rrr to align the stacks.
If the coherence is negative, the algorithm performs separate rotations for each stack.
Example in Code
From the provided code in algorithm_helper.c:

The coherence is subtracted from the total cost (count_op) to account for the overlap in rotations.
Summary
Coherence is a key optimization in the Push Swap algorithm. By aligning the rotations of stack_a and stack_b, the algorithm reduces the total number of operations, making the sorting process more efficient.