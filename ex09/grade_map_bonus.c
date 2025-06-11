#include "grade_map.h"

static GradeNode* find_grade_node(GradeNode *head, const char *grade)
{
    while (head)
    {
        if (strcmp(head->grade, grade) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

// Compute the distribution of grades
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
            if (!new_node)
                continue;
            new_node->grade = mapped_grades[i];
            new_node->count = 1;
            new_node->next = head;
            head = new_node;
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
/*
int main(void)
{
    int scores[] = {100, 95, 82, 67, 59, 95, 82, 59, 100, 67};
    int size = sizeof(scores) / sizeof(scores[0]);
    const char *mapped_grades[size];

    map_scores(scores, size, plusminus_mapper, mapped_grades);

    printf("Mappatura voti:\n");
    for (int i = 0; i < size; ++i)
        printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

    GradeNode *dist = compute_distribution(mapped_grades, size);

    print_distribution(dist);

    free_distribution(dist);

    return 0;
}*/
