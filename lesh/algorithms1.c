#include "push_swap.h"

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the index of a specific value in the stack
int find_index1(t_stack *stack, int value) {
    int index = 0;
    
    while (stack) {
        if (stack->data == value) {
            return index;
        }
        stack = stack->next;
        index++;
    }
    
    return -1; // Return -1 if the value is not found in the stack
}

// Function to calculate the cost of bringing a value to the top of the stack
int calculate_cost(t_stack *a, t_stack *b, t_stack *target) {
    int cost_a = 0;
    int cost_b = 0;
    
    // Calculate cost to move value to top of stack A
    t_stack *current = a;
    while (current && current->data != target->data) {
        cost_a++;
        current = current->next;
    }
    
    // Calculate cost to move target to top of stack B
    current = b;
    while (current && current->data != target->data) {
        cost_b++;
        current = current->next;
    }
    
    // Consider both rotating and reverse rotating for minimal cost
    cost_a = min(cost_a, stack_len(a) - cost_a);
    cost_b = min(cost_b, stack_len(b) - cost_b);
    
    return cost_a + cost_b;
}

// Function to find the closest smaller number in stack B or the maximum if none
t_stack *find_target(t_stack *b, int value) {
    t_stack *current = b;
    t_stack *target = NULL;
    
    while (current) {
        if (current->data < value && (!target || current->data > target->data)) {
            target = current;
        }
        current = current->next;
    }
    
    if (!target) {
        current = b;
        target = current;
        while (current) {
            if (current->data > target->data) {
                target = current;
            }
            current = current->next;
        }
    }
    
    return target;
}

void move_value_to_top(t_stack **stack, int value, char stack_name)
{
    int index = find_index1(*stack, value);
    int len = stack_len(*stack);
    
    printf("index %d\n", index);
    if (index <= len / 2) {
        while ((*stack)->data != value) {
            if (stack_name == 'a') {
                ra(stack); // Rotate stack 'a'
            } else if (stack_name == 'b') {
                rb(stack); // Rotate stack 'b'
            }
        }
    } else {
        while ((*stack)->data != value) {
            if (stack_name == 'a') {
                rra(stack); // Reverse rotate stack 'a'
            } else if (stack_name == 'b') {
                rrb(stack); // Reverse rotate stack 'b'
            }
        }
    }
}

// void check_ra(t_stack **stack, int median)
// {
//     if ()
// }

// Function to push from stack A to stack B considering the minimum cost
void push_min_cost(t_stack **a, t_stack **b) {
    t_stack *current_a = *a;
    t_stack *min_cost_target = NULL;
    t_stack *target;
    int min_cost = INT_MAX;
    int current_cost;
    
    while (stack_len(*a) > 3) {
        min_cost = INT_MAX;
        current_a = *a;
        
        // Iterate through all elements in A to find the minimum cost
        while (current_a) {
            target = find_target(*b, current_a->data);
            current_cost = calculate_cost(*a, *b, target);
            
            if (current_cost < min_cost) {
                min_cost = current_cost;
                min_cost_target = current_a;
            }
            
            current_a = current_a->next;
        }
        ft_printf("minimum cost number : %d and its cost: %d\n", target->data, min_cost);
        // Move the element in A and its target in B to the top of their stacks
        move_value_to_top(a, min_cost_target->data, 'a');
        move_value_to_top(b, find_target(*b, min_cost_target->data)->data, 'b');
        
        // Push from A to B
        pb(a, b);
    }
}
