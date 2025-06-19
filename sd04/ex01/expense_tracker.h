#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#define MAX_EXPENSES 1000
#define MAX_LINE_LEN 1024

typedef struct s_expense
{
    char    date[11];
    double  amount;
    char    *category;
    char    *description;
}   t_expense;

typedef struct s_expense_list
{
    t_expense   expenses[MAX_EXPENSES];
    int         count;
}   t_expense_list;

typedef struct s_category_summary
{
    char    *category;
    double  total;
    double  percentage;
    int     count;
}   t_category_summary;

int     load_expenses(const char *filename, t_expense_list *list);
int     filter_by_category(const t_expense_list *list, const char *substr, t_expense *results, int max_results);
int     filter_by_date_range(const t_expense_list *list, const char *start, const char *end, t_expense *results, int max_results);
void    print_summary(const t_expense *expenses, int count);
void    free_expense_list(t_expense_list *list);
char    *str_trim(char *str);
int     strcasestr_custom(const char *haystack, const char *needle);
int     is_valid_date(const char *date);
int     compare_dates(const char *date1, const char *date2);

#endif