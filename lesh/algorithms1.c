#include "push_swap.h"

// Function to find the closest smaller number in stack B or the maximum if none exists
t_stack *find_target(t_stack *b, int value) {
    t_stack *target = NULL;
    t_stack *current = b;
    int max_value = INT_MIN;

    while (current) {
        if (current->data < value && (!target || current->data > target->data)) {
            target = current;
        }
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }

    if (!target) {
        current = b;
        while (current) {
            if (current->data == max_value) {
                target = current;
                break;
            }
            current = current->next;
        }
    }

    return target;
}

// Function to calculate the cost of moving a number to the top of stack A and its target to the top of stack B
int calculate_cost(t_stack *a, t_stack *b, t_stack *target) {
    int cost = 0;
    t_stack *current = a;

    // Calculate cost to move the number to the top of stack A
    while (current && current->data != target->data) {
        cost++;
        current = current->next;
    }

    // Calculate cost to move the target to the top of stack B
    current = b;
    while (current && current->data != target->data) {
        cost++;
        current = current->next;
    }

    return cost;
}

// Function to push the number with the minimum cost from stack A to stack B
void push_min_cost(t_stack **a, t_stack **b) {
    t_stack *current = *a;
    t_stack *min_cost_node = NULL;
    t_stack *target = NULL;
    int min_cost = INT_MAX;

    // Find the number with the minimum cost
    while (current) {
        t_stack *current_target = find_target(*b, current->data);
        int cost = calculate_cost(*a, *b, current_target);
        if (cost < min_cost) {
            min_cost = cost;
            min_cost_node = current;
            target = current_target;
        }
        current = current->next;
    }

    // Move the number and its target to the top of their respective stacks
    move_value_to_top(a, min_cost_node->data);
    move_value_to_top(b, target->data);

    // Push the number from stack A to stack B
    pb(a, b);
}

// Function to move a value to the top of the stack

void move_value_to_top(t_stack **stack, int value) {
    t_stack *current = *stack;
    int position = 0;

    // Find the position of the value in the stack
    while (current && current->data != value) {
        position++;
        current = current->next;
    }

    // Rotate or reverse rotate to move the value to the top
    if (position <= stack_len(*stack) / 2) {
        while ((*stack)->data != value) {
            ra(stack);
        }
    } else {
        while ((*stack)->data != value) {
            rra(stack);
        }
    }
}

