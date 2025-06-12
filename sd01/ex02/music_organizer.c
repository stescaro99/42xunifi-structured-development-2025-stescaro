#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    struct MusicLibrary *lib = create_music_library();
    if (!lib)
        return NULL;
    const char **scan = scan_directory(directory_path);
    if (!scan)
    {
        free(lib);
        return NULL;
    }
    for (int i=0; scan[i]; i++)
    {
        struct MusicFile *file = process_music_file(directory_path, scan[i]);
        if (!file)
        {
            free(lib);
            return NULL;
        }
        update_music_library(lib, file);
        free(file);
    }
}
