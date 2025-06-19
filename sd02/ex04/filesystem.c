#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
    FSNode *node = (FSNode *)malloc(sizeof(FSNode));
    if (!node)
        return NULL;
    node->name = strdup(name);
    node->size = size;
    node->parent = NULL;
    node->children = NULL;
    node->sibling = NULL;
    return node;
}

FSNode *create_folder(const char *name)
{
    FSNode *node = (FSNode *)malloc(sizeof(FSNode));
    if (!node)
        return NULL;
    node->name = strdup(name);
    node->size = 0;
    node->parent = NULL;
    node->children = NULL;
    node->sibling = NULL;
    return node;
}

void add_child(FSNode *parent, FSNode *child)
{
    FSNode *tmp;
    if (!parent || !child)
        return;
    child->parent = parent;
    if (!parent->children)
        parent->children = child;
    else
    {
        tmp = parent->children;
        while (tmp->sibling)
            tmp = tmp->sibling;
        tmp->sibling = child;
    }
}

FSNode *get_children(const FSNode *parent)
{
    if (!parent)
        return NULL;
    return parent->children;
}

FSNode *get_sibling(const FSNode *node)
{
    if (!node)
        return NULL;
    return node->sibling;
}
