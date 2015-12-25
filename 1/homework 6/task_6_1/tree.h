#pragma once

struct TreeNode;

struct Tree;

Tree *createTree();
bool addTreeNode(Tree *tree, int x);
TreeNode **search(Tree *tree, int x);
bool removeTreeNode(Tree *tree, int x);
void clearTree(Tree *tree);
void printTree(Tree *tree);
void printInfix(Tree *tree);
void printLargestToSmallest(Tree *tree);
