#include "music_organizer.h"

int process_music_files(struct MusicLibrary *lib, const char *directory_path, const char **scan)
{
    int i = 0;
    int error = 0;
    struct MusicFile *file = NULL;

    while (scan[i])
    {
        file = process_music_file(directory_path, scan[i]);
        if (!file)
            error = 1;
        else
        {
            update_music_library(lib, file);
            free(file);
        }
        i++;
    }
    return error;
}

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    struct MusicLibrary *lib = NULL;
    const char **scan = NULL;
    int error = 0;

    if (!directory_path)
        return NULL;
    lib = create_music_library();
    if (!lib)
        return NULL;
    scan = scan_directory(directory_path);
    if (!scan)
    {
        free(lib);
        return NULL;
    }
    error = process_music_files(lib, directory_path, scan);
    if (error)
    {
        free(lib);
        lib = NULL;
    }
    return lib;
}
