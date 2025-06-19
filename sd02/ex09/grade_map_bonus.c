#include "grade_map.h"

static GradeNode* find_grade_node(GradeNode *head, const char *grade)
{
    GradeNode *found = NULL;
    while (head)
    {
        if (strcmp(head->grade, grade) == 0)
            found = head;
        head = head->next;
    }
    return found;
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
            GradeNode *new_node = (GradeNode *)malloc(sizeof(GradeNode));
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
    GradeNode *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
