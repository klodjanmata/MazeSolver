#include <stdio.h>
#include <stdbool.h>

#define MAZE_SIZE 10
#define STACK_SIZE 30

typedef struct
{
    int x, y;
} coordinate;

coordinate stack[STACK_SIZE];
int top = -1;

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

int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == STACK_SIZE)
        return 1;
    else
        return 0;
}

coordinate peek()
{
    return stack[top];
}

coordinate pop()
{
    if (!isempty())
    {
        coordinate data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Stack is empty.\n");
        coordinate data;
        data.x = -1;
        data.y = -1;
        return data;
    }
}

void push(coordinate data)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int find_entrance(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{

    return 0;
}