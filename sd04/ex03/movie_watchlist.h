#ifndef MOVIE_WATCHLIST_H
#define MOVIE_WATCHLIST_H

#define MAX_MOVIES 1000
#define MAX_LINE_LEN 1024

typedef struct s_movie
{
    int     id;
    char    *title;
    char    *genre;
    int     watched;
    int     rating;
    char    date_watched[11];
}   t_movie;

typedef struct s_movie_list
{
    t_movie movies[MAX_MOVIES];
    int     count;
    int     max_id;
}   t_movie_list;

int     load_movies(const char *filename, t_movie_list *list);
int     save_movies(const char *filename, const t_movie_list *list);
void    list_movies(const t_movie_list *list);
int     search_by_title(const t_movie_list *list, const char *substr, t_movie *results, int max_results);
int     search_by_genre(const t_movie_list *list, const char *substr, t_movie *results, int max_results);
int     filter_by_watched(const t_movie_list *list, int watched_flag, t_movie *results, int max_results);
int     add_movie(t_movie_list *list, const t_movie *new_movie);
int     mark_as_watched(t_movie_list *list, int id, int rating, const char *date_watched);
int     update_movie(t_movie_list *list, int id, const char *new_title, const char *new_genre);
int     delete_movie(t_movie_list *list, int id);
void    show_summary(const t_movie_list *list);
char    *str_trim(char *str);
int     strcasestr_custom(const char *haystack, const char *needle);
int     is_valid_date(const char *date);
int     is_unique_id(const t_movie_list *list, int id);
void    free_movie_list(t_movie_list *list);

#endif