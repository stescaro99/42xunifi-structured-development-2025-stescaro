#include "../ex04/filesystem.h"
#include <stdio.h>

int compute_total_size(const FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);
