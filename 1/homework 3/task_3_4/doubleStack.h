#pragma once
#include <cstddef>

struct StackNode;

struct Stack;

Stack createStack();
double showTop(Stack s);
void push(Stack &s, double x);
double pop(Stack &s);
void deleteStack(Stack &s);
bool haveTwoStackNode(Stack s);
