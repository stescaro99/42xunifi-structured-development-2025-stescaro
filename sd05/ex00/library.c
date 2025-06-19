#include "library.h"

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
    size_t i, j;
    if (nlen == 0)
        return 1;
    for (i = 0; i <= hlen - nlen; i++)
    {
        j = 0;
        while (j < nlen &&
               tolower((unsigned char)haystack[i + j]) == tolower((unsigned char)needle[j]))
            j++;
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
        if (title_raw)
            free(title_raw);
        if (author_raw)
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

static void handle_parse_result(int parse_ok, t_book *tmp)
{
    if (!parse_ok)
    {
        if (tmp->title)
            free(tmp->title);
        if (tmp->author)
            free(tmp->author);
    }
}

int load_catalog(const char *filename, t_catalog *catalog)
{
    FILE *f;
    char line[MAX_LINE_LEN];
    int count = 0;
    int parse_ok;
    if (!filename || !catalog)
        return 0;
    f = fopen(filename, "r");
    if (!f)
        return 0;
    while (fgets(line, sizeof(line), f) && count < MAX_BOOKS)
    {
        t_book tmp;
        char *lineptr = strdup(line);
        int should_store = 0;

        tmp.title = NULL;
        tmp.author = NULL;

        if (lineptr)
        {
            parse_ok = parse_line(lineptr, &tmp);
            if (parse_ok)
            {
                catalog->books[count].id = tmp.id;
                catalog->books[count].title = tmp.title;
                catalog->books[count].author = tmp.author;
                should_store = 1;
                count++;
            }
            handle_parse_result(parse_ok, &tmp);
            free(lineptr);
        }
    }
    fclose(f);
    catalog->count = count;
    return count;
}

int search_by_title(const t_catalog *catalog, const char *substr, t_book *results, int max_results)
{
    int found = 0;
    int i;
    if (!catalog || !substr || !results || max_results <= 0)
        return 0;
    for (i = 0; i < catalog->count && found < max_results; i++)
    {
        if (strcasestr_custom(catalog->books[i].title, substr))
            results[found++] = catalog->books[i];
    }
    return found;
}

int search_by_author(const t_catalog *catalog, const char *substr, t_book *results, int max_results)
{
    int found = 0;
    int i;
    if (!catalog || !substr || !results || max_results <= 0)
        return 0;
    for (i = 0; i < catalog->count && found < max_results; i++)
    {
        if (strcasestr_custom(catalog->books[i].author, substr))
            results[found++] = catalog->books[i];
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
    int i;
    if (!catalog)
        return;
    for (i = 0; i < catalog->count; i++)
    {
        free(catalog->books[i].title);
        free(catalog->books[i].author);
    }
    catalog->count = 0;
}