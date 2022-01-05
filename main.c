#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define MAZE_SIZE 10
#define STACK_SIZE 30

typedef struct
{
    int x, y;
} cordinate;

int maze[MAZE_SIZE][MAZE_SIZE] = {
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};

struct Stack
{
    int top;
    unsigned capacity;
    cordinate *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (cordinate *)malloc(stack->capacity * sizeof(cordinate));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack *stack, cordinate item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("(%d, %d) pushed to stack\n", item.x, item.y);
}

void push_separately(struct Stack *stack, int x, int y)
{
    if (isFull(stack))
        return;
    cordinate item;
    item.x = x;
    item.y = y;
    stack->array[++stack->top] = item;
    printf("(%d, %d) pushed to stack\n", item.x, item.y);
}

// Function to remove an item from stack.  It decreases top by 1
cordinate pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return;
    printf("(%d, %d) poped to stack\n", stack->array[stack->top].x, stack->array[stack->top].y);
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
cordinate peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main()
{
    struct Stack *stack = createStack(STACK_SIZE);
    cordinate item;
    item.x = 2;
    item.y = 3;
    push_separately(stack, 10, 10);
    push(stack, item);
    push(stack, item);
    item = pop(stack);

    return 0;
}