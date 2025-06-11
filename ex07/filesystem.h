#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct FSNode {
    char* name;
    int size;
    struct FSNode* parent;
    struct FSNode* children;
    struct FSNode* sibling;
} FSNode;

FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);

int compute_total_size(const FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);
