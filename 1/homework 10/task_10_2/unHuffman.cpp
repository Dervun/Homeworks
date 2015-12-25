#include "unHuffman.h"
#include "tree.h"

void unarchive(FILE* stream)
{
    Tree* tree = fscanfTree(stream);
    fscanf(stream, "\n");
    uncode(stream, tree);
    clearTree(tree);
}
