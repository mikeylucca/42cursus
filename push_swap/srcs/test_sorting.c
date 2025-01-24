#include <stdio.h>
#include "../includes/push_swap.h"

void test_stack_sorted() {
    t_stack *a = NULL;

    // Test case 1: Empty stack
    printf("Test 1 (Empty stack): %s\n", stack_sorted(a) ? "Passed" : "Failed");

    // Test case 2: Single element
    push(&a, create_node(1));
    printf("Test 2 (Single element): %s\n", stack_sorted(a) ? "Passed" : "Failed");

    // Test case 3: Sorted stack
    push(&a, create_node(2));
    push(&a, create_node(1));
    printf("Test 3 (Sorted stack): %s\n", stack_sorted(a) ? "Passed" : "Failed");

    // Test case 4: Unsorted stack
    push(&a, create_node(3));
    printf("Test 4 (Unsorted stack): %s\n", stack_sorted(a) ? "Passed" : "Failed");

    // Clean up
    free_stack(a);
}

int main() {
    test_stack_sorted();
    return 0;
}
