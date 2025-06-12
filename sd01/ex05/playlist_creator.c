#include "playlist_creator.h"

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood = analyze_user_mood();
    if (!mood)
        return NULL;
    struct FilterSettings *df = default_filters();
    if (!df)
        return (free_mood_settings(), NULL);
    int mv = get_mood_variation(mood);
    for (int i = 0; i < mv; ++i)
    {
        struct FilterSettings *new_filters = refine_filters(df);
        if (!new_filters)
            return (free_filter_settings(df), free_mood_settings(mood), NULL);
        if (new_filters != df)
        {
            free_filter_settings(df);
            df = new_filters;
        }
    }
    struct SongData *song = NULL;
    if (filters_require_popular_song(df))
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
    if (!song)
        return (free_filter_settings(df), free_mood_settings(mood), NULL);
    struct Playlist *playlist = combine_with_mood_playlist(song, mood);
    return (free_song_data(song), free_filter_settings(df), free_mood_settings(mood), playlist);
}