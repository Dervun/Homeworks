#pragma once

struct StackNode{
    double value;
    StackNode *next;
};

struct Stack{
    StackNode *top;
};

Stack createStack();
double showTop(Stack s);
void push(Stack &s, double x);
double pop(Stack &s);
void deleteStack(Stack &s);
bool haveTwoStackNode(Stack s);
