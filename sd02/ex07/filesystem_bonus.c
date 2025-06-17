#include "filesystem.h"

int compute_total_size(const FSNode *node)
{
    if (!node)
        return 0;
    int total = 0;
    const FSNode *tmp = get_children(node);
    while (tmp)
    {
        if (tmp->size == 0)
            total += compute_total_size(tmp);
        else
            total += tmp->size;
        tmp = get_sibling(tmp);
    }
    return total;
}

void print_structure(const FSNode *node, int indent)
{
    if (!node)
        return;
    for (int i = 0; i < indent; i++)
        printf("  ");
    if (node->size == 0)
        printf("[DIR] %s\n", node->name);
    else
        printf("%s (%d)\n", node->name, node->size);
    const FSNode *child = get_children(node);
    while (child)
    {
        print_structure(child, indent + 1);
        child = get_sibling(child);
    }
}

void free_filesystem(FSNode *node)
{
    if (!node)
        return ;
    FSNode *tmp = get_children(node);
    while (tmp)
    {
        FSNode *sibling = get_sibling(tmp);
        free_filesystem(tmp);
        tmp = sibling;                   
    }
    free(node->name);
    free(node);
}