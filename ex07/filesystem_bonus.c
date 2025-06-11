#include "filesystem.h"

int compute_total_size(FSNode *node)
{
    if (!node)
        return 0;
    int total = 0;
    FSNode *tmp = get_children(node);
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

/*
int main()
{
    FSNode *root = create_folder("root");
    FSNode *docs = create_folder("docs");
    FSNode *img = create_folder("images");
    FSNode *file1 = create_file("file1.txt", 100);
    FSNode *file2 = create_file("file2.txt", 200);
    FSNode *pic1 = create_file("pic1.jpg", 500);

    add_child(root, docs);
    add_child(root, img);
    add_child(docs, file1);
    add_child(docs, file2);
    add_child(img, pic1);

    printf("Struttura del filesystem:\n");
    print_structure(root, 0);

    int total = compute_total_size(root);
    printf("\nDimensione totale: %d\n", total);

    free_filesystem(root);

    return 0;
}*/