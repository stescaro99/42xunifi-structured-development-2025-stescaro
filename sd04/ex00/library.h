#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 1000
#define MAX_LINE_LEN 1024

#include "../../utils/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct s_book
{
    int     id;
    char    *title;
    char    *author;
}   t_book;

typedef struct s_catalog
{
    t_book  books[MAX_BOOKS];
    int     count;
}   t_catalog;

int     load_catalog(const char *filename, t_catalog *catalog);
int     search_by_title(const t_catalog *catalog, const char *substr, t_book *results, int max_results);
int     search_by_author(const t_catalog *catalog, const char *substr, t_book *results, int max_results);
void    print_book(const t_book *book);
void    free_catalog(t_catalog *catalog);
char    *str_trim(char *str);
int     strcasestr_custom(const char *haystack, const char *needle);

#endif