#include "utils.h"

const char* plusminus_mapper(int score)
{
    if (score >= 97 && score <= 100)
        return "A+";
    if (score >= 93 && score <= 96)
        return "A";
    if (score >= 90 && score <= 92)
        return "A-";
    if (score >= 87 && score <= 89)
        return "B+";
    if (score >= 83 && score <= 86)
        return "B";
    if (score >= 80 && score <= 82)
        return "B-";
    if (score >= 77 && score <= 79)
        return "C+";
    if (score >= 73 && score <= 76)
        return "C";
    if (score >= 70 && score <= 72)
        return "C-";
    if (score >= 67 && score <= 69)
        return "D+";
    if (score >= 63 && score <= 66)
        return "D";
    if (score >= 60 && score <= 62)
        return "D-";
    return "F";
}

const char* passfail_mapper(int score)
{
    if (score >= 60 && score <= 100)
        return "P";
    return "F";
}

const char* standard_mapper(int score)
{
    if (score >= 90 && score <= 100)
        return "A";
    if (score >= 80 && score <= 89)
        return "B";
    if (score >= 70 && score <= 79)
        return "C";
    if (score >= 60 && score <= 69)
        return "D";
    return "F";
}
