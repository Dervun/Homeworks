#pragma once

struct TreeNode;
struct Tree;

Tree *createTree();
void clearTree(Tree *tree);
Tree* readTree(char *stringTree);
char* treeToPostfix(Tree* tree);
void printInfix(Tree* tree);
