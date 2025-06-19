#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#define MAX_CONTACTS 1000
#define MAX_LINE_LEN 1024

typedef struct s_contact
{
    int     id;
    char    *name;
    char    *phone;
    char    *email;
    char    *city;
    char    *address;
}   t_contact;

typedef struct s_contact_list
{
    t_contact   contacts[MAX_CONTACTS];
    int         count;
    int         max_id;
}   t_contact_list;

int     load_contacts(const char *filename, t_contact_list *list);
int     save_contacts(const char *filename, const t_contact_list *list);
void    list_contacts(const t_contact_list *list);
int     search_by_name(const t_contact_list *list, const char *substr, t_contact *results, int max_results);
int     search_by_city(const t_contact_list *list, const char *substr, t_contact *results, int max_results);
int     add_contact(t_contact_list *list, const t_contact *new_contact);
int     update_contact(t_contact_list *list, int id, const t_contact *updated_contact);
int     delete_contact(t_contact_list *list, int id);
char    *str_trim(char *str);
int     strcasestr_custom(const char *haystack, const char *needle);
int     is_valid_email(const char *email);
int     is_valid_phone(const char *phone);
int     is_unique_id(const t_contact_list *list, int id);
void    free_contact_list(t_contact_list *list);

#endif