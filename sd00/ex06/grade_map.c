#include "grade_map.h"

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    for (int i = 0; i < size; ++i)
        mapped_grades[i] = mapper(scores[i]);
}