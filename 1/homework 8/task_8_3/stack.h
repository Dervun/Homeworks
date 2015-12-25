#pragma once

struct StackNode;
struct Stack;

Stack* createStack();
int showTop(Stack* s);
void push(Stack* s, int x);
int pop(Stack* s);
void deleteStack(Stack* s);
bool emptyStack(Stack* s);
