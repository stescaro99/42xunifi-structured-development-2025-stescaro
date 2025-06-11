#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
    FSNode *newnode = malloc(sizeof(FSNode));
    newnode->name = strdup(name);
    newnode->size = size;
    newnode->parent = NULL;
    newnode->children = NULL;
    newnode->sibling = NULL;
    return newnode;
}

FSNode *create_folder(const char *name)
{
    FSNode *newnode = malloc(sizeof(FSNode));
    newnode->name = strdup(name);
    newnode->size = 0;
    newnode->parent = NULL;
    newnode->children = NULL;
    newnode->sibling = NULL;
    return newnode;
}

void add_child(FSNode *parent, FSNode *child)
{
    if (!parent || !child)
    	return;
    child->parent = parent;
    if (!parent->children)
    {
        parent->children = child;
    }
    else
    {
        FSNode *tmp = parent->children;
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

//test nel ex07
