#include "playlist_creator.h"

static int refine_all_filters(struct FilterSettings **df, int mv)
{
    int i = 0;
    int error = 0;
    while (i < mv)
    {
        struct FilterSettings *new_filters = refine_filters(*df);
        if (!new_filters)
            error = 1;
        else if (new_filters != *df)
        {
            free_filter_settings(*df);
            *df = new_filters;
        }
        i++;
    }
    return error;
}

static struct FilterSettings *get_final_filters(struct MoodSettings *mood, int *error)
{
    struct FilterSettings *df = default_filters();
    int mv;

    *error = 0;
    if (!df)
    {
        *error = 1;
        return NULL;
    }
    mv = get_mood_variation(mood);
    if (refine_all_filters(&df, mv))
    {
        free_filter_settings(df);
        *error = 1;
        return NULL;
    }
    return df;
}

static struct SongData *get_song(struct FilterSettings *df)
{
    if (filters_require_popular_song(df))
        return fetch_popular_song();
    return fetch_niche_song();
}

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood = NULL;
    struct FilterSettings *df = NULL;
    struct SongData *song = NULL;
    struct Playlist *playlist = NULL;
    int error = 0;

    mood = analyze_user_mood();
    if (!mood)
        return NULL;
    df = get_final_filters(mood, &error);
    if (error)
    {
        free_mood_settings(mood);
        return NULL;
    }
    song = get_song(df);
    if (!song)
    {
        free_filter_settings(df);
        free_mood_settings(mood);
        return NULL;
    }
    playlist = combine_with_mood_playlist(song, mood);
    free_song_data(song);
    free_filter_settings(df);
    free_mood_settings(mood);

    return playlist;
}