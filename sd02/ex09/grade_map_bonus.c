#include "grade_map.h"

static GradeNode* find_grade_node(GradeNode *head, const char *grade)
{
    int len = 0;
    while (head && len > -1)
    {
        if (strcmp(head->grade, grade) == 0)
            len = -100;
        head = head->next;
        len++;
    }
    if (len < 0)
        return head;
    return NULL;
}

GradeNode *compute_distribution(const char **mapped_grades, int size)
{
    GradeNode *head = NULL;
    for (int i = 0; i < size; ++i)
    {
        GradeNode *node = find_grade_node(head, mapped_grades[i]);
        if (node)
            node->count++;
        else
        {
            GradeNode *new_node = malloc(sizeof(GradeNode));
            if (new_node)
            {
                new_node->grade = mapped_grades[i];
                new_node->count = 1;
                new_node->next = head;
                head = new_node;
            }
        }
    }
    return head;
}

void print_distribution(GradeNode *head)
{
    printf("Grade Distribution:\n");
    while (head)
    {
        printf("Grade %s: %d\n", head->grade, head->count);
        head = head->next;
    }
}

void free_distribution(GradeNode *head)
{
    while (head)
    {
        GradeNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}
