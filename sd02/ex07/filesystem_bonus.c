#include "filesystem.h"

int compute_total_size(const FSNode *node)
{
    int total = 0;
    const FSNode *child;
    if (!node)
        return 0;
    child = get_children(node);
    while (child)
    {
        if (child->size == 0)
            total += compute_total_size(child);
        else
            total += child->size;
        child = get_sibling(child);
    }
    return total;
}

void print_structure(const FSNode *node, int indent)
{
    int i;
    const FSNode *child;
    if (!node)
        return;
    for (i = 0; i < indent; i++)
        printf("  ");
    if (node->size == 0)
        printf("[DIR] %s\n", node->name);
    else
        printf("%s (%d)\n", node->name, node->size);
    child = get_children(node);
    while (child)
    {
        print_structure(child, indent + 1);
        child = get_sibling(child);
    }
}

void free_filesystem(FSNode *node)
{
    FSNode *child, *sibling;
    if (!node)
        return;
    child = get_children(node);
    while (child)
    {
        sibling = get_sibling(child);
        free_filesystem(child);
        child = sibling;
    }
    free(node->name);
    free(node);
}