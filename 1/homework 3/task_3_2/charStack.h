#pragma once

struct CharStackNode;

struct CharStack;

CharStack createCharStack();
char showCharTop(CharStack s);
void pushChar(CharStack &s, char x);
char popChar(CharStack &s);
void deleteCharStack(CharStack &s);
bool emptyCharStack(CharStack s);
