#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef const char* (*GradeMapper)(int score);

typedef struct GradeNode {
    const char *grade;
    int count;
    struct GradeNode *next;
} GradeNode;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

const char* standard_mapper(int score);
const char* passfail_mapper(int score);
const char* plusminus_mapper(int score);

GradeNode *compute_distribution(const char **mapped_grades, int size);
void print_distribution(GradeNode *head);
void free_distribution(GradeNode *head);