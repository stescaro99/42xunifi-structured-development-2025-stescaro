#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
    struct Preferences *prefs = get_user_preferences();
    if (!prefs)
        return NULL;
    struct MovieList *movies = find_movies(prefs);
    if (!movies)
    {
        free(prefs);
        return NULL;
    }
    struct Plan *plan = build_plan(movies);
    free(prefs);
    free(movies);
    return plan;
}