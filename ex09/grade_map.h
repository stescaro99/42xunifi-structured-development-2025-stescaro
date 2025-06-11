#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../ex06/grade_map.h"

typedef struct GradeNode {
    const char *grade;
    int count;
    struct GradeNode *next;
} GradeNode;

GradeNode *compute_distribution(const char **mapped_grades, int size);
void print_distribution(GradeNode *head);
void free_distribution(GradeNode *head);