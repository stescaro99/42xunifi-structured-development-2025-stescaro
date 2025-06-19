#include "library.h"

static char *dup_trim(const char *src)
{
    char *tmp = strdup(src);
    if (!tmp)
        return NULL;
    str_trim(tmp);
    return tmp;
}

char *str_trim(char *str)
{
    char *end;
    while (isspace((unsigned char)*str))
        str++;
    if (*str == 0)
        return str;
    end = str + ft_strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;
    *(end + 1) = 0;
    return str;
}

static int parse_line(char *line, t_book *book)
{
    char *fields[3];
    int i = 0;
    char *saveptr = NULL;
    char *token = strtok_r(line, ",", &saveptr);

    while (token && i < 3)
    {
        fields[i++] = token;
        token = strtok_r(NULL, ",", &saveptr);
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
    const char *title_trimmed = str_trim(title_raw);
    const char *author_trimmed = str_trim(author_raw);
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
    if (!parse_ok && tmp)
    {
        if (tmp->title)
            free(tmp->title);
        if (tmp->author)
            free(tmp->author);
    }
}

static int open_file(const char *filename, FILE **f)
{
    if (!filename || !f)
        return 0;
    *f = fopen(filename, "r");
    return (*f != NULL);
}

static int read_line(FILE *f, char *line, size_t size)
{
    if (!f || !line || size == 0)
        return 0;
    return (fgets(line, size, f) != NULL);
}

static int process_line(const char *line, t_book *tmp)
{
    char *lineptr = strdup(line);
    int ok = 0;
    if (lineptr)
    {
        tmp->title = NULL;
        tmp->author = NULL;
        ok = parse_line(lineptr, tmp);
        free(lineptr);
    }
    return ok;
}

int load_catalog(const char *filename, t_catalog *catalog)
{
    FILE *f;
    char line[MAX_LINE_LEN];
    int count = 0;

    if (!open_file(filename, &f))
        return 0;

    while (read_line(f, line, sizeof(line)) && count < MAX_BOOKS)
    {
        t_book tmp;
        int parse_ok = process_line(line, &tmp);
        if (parse_ok)
        {
            catalog->books[count].id = tmp.id;
            catalog->books[count].title = tmp.title;
            catalog->books[count].author = tmp.author;
            count++;
        }
        handle_parse_result(parse_ok, &tmp);
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
            results[found++] = catalog->books[i];
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

    char *dummy = dup_trim("  prova dup_trim  ");
    if (dummy)
    {
        printf("Dummy trim: '%s'\n", dummy);
        free(dummy);
    }

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