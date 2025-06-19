#include "library.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char *dup_trim(const char *src)
{
    char *tmp = strdup(src);

    if (!tmp)
        return NULL;
    return str_trim(tmp);
}

char *str_trim(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;
    if (*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;
    *(end + 1) = 0;
    return str;
}

int strcasestr_custom(const char *haystack, const char *needle)
{
    size_t nlen = strlen(needle);
    size_t hlen = strlen(haystack);
    size_t i;
    size_t j;

    if (nlen == 0)
        return 1;
    for (i = 0; i <= hlen - nlen; i++)
    {
        for (j = 0; j < nlen; j++)
        {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j]))
                break;
        }
        if (j == nlen)
            return 1;
    }
    return 0;
}

static int parse_line(char *line, t_book *book)
{
    char *fields[3];
    int i = 0;
    char *token = strtok(line, ",");

    while (token && i < 3)
    {
        fields[i++] = token;
        token = strtok(NULL, ",");
    }
    if (i != 3)
        return 0;
    book->id = atoi(str_trim(fields[0]));
    if (book->id <= 0)
        return 0;
    char *title_raw = strdup(fields[1]);
    char *author_raw = strdup(fields[2]);
    if (!title_raw || !author_raw)
    {
        free(title_raw);
        free(author_raw);
        return 0;
    }
    char *title_trimmed = str_trim(title_raw);
    char *author_trimmed = str_trim(author_raw);
    if (!*title_trimmed || !*author_trimmed)
    {
        free(title_raw);
        free(author_raw);
        return 0;
    }
    book->title = title_raw;
    book->author = author_raw;
    return 1;
}

int load_catalog(const char *filename, t_catalog *catalog)
{
    FILE *f;
    char line[MAX_LINE_LEN];
    int count = 0;
    if (!filename || !catalog)
        return 0;
    f = fopen(filename, "r");
    if (!f)
        return 0;
    while (fgets(line, sizeof(line), f) && count < MAX_BOOKS)
    {
        t_book tmp;
        char *lineptr = strdup(line);
        if (!lineptr)
            continue;
        if (parse_line(lineptr, &tmp))
        {
            catalog->books[count].id = tmp.id;
            catalog->books[count].title = tmp.title;
            catalog->books[count].author = tmp.author;
            count++;
        }
        else
        {
            free(tmp.title);
            free(tmp.author);
        }
    }
    fclose(f);
    catalog->count = count;
    return count;
}

int search_by_title(const t_catalog *catalog, const char *substr, t_book *results, int max_results)
{
    int found = 0;
    
    if (!catalog || !substr || !results || max_results <= 0)
        return 0;
    for (int i = 0; i < catalog->count && found < max_results; i++)
    {
        if (strcasestr_custom(catalog->books[i].title, substr))
        {
            results[found++] = catalog->books[i];
        }
    }
    return found;
}

int search_by_author(const t_catalog *catalog, const char *substr, t_book *results, int max_results)
{
    int found = 0;
    
    if (!catalog || !substr || !results || max_results <= 0)
        return 0;
    for (int i = 0; i < catalog->count && found < max_results; i++)
    {
        if (strcasestr_custom(catalog->books[i].author, substr))
        {
            results[found++] = catalog->books[i];
        }
    }
    return found;
}

void print_book(const t_book *book)
{
    if (!book)
        return;
    printf("ID: %d\nTitle: %s\nAuthor: %s\n", book->id, book->title, book->author);
}

void free_catalog(t_catalog *catalog)
{
    if (!catalog)
        return;
    for (int i = 0; i < catalog->count; i++)
    {
        free(catalog->books[i].title);
        free(catalog->books[i].author);
    }
    catalog->count = 0;
}

int main(void)
{
    t_catalog catalog;
    t_book results[10];
    int found;

    if (!load_catalog("books.csv", &catalog))
    {
        printf("Failed to load catalog\n");
        return 1;
    }
    found = search_by_title(&catalog, "harry", results, 10);
    for (int i = 0; i < found; i++)
        print_book(&results[i]);
    free_catalog(&catalog);
    return 0;
}