# Movie Watchlist - Struttura del file `movie_watchlist.h`

## Strutture Dati

- **t_movie**  
  Rappresenta un film nella watchlist:
  - `id`: identificatore numerico positivo e univoco
  - `title`: titolo del film
  - `genre`: genere del film
  - `watched`: flag (0 = non visto, 1 = visto)
  - `rating`: voto da 1 a 10 se visto, 0 se non visto
  - `date_watched`: data in cui è stato visto ("YYYY-MM-DD"), vuota se non visto

- **t_movie_list**  
  Contiene tutti i film caricati:
  - `movies`: array di massimo 1000 film
  - `count`: numero di film validi
  - `max_id`: ID massimo presente

## Prototipi di Funzione

- **Caricamento e salvataggio**
  - `int load_movies(const char *filename, t_movie_list *list);`  
    Carica i film dal file CSV, saltando e segnalando le righe invalide.
  - `int save_movies(const char *filename, const t_movie_list *list);`  
    Salva tutti i film su file.

- **Operazioni principali**
  - `void list_movies(const t_movie_list *list);`  
    Elenca tutti i film in ordine di ID.
  - `int search_by_title(const t_movie_list *list, const char *substr, t_movie *results, int max_results);`  
    Cerca per sottostringa nel titolo (case-insensitive).
  - `int search_by_genre(const t_movie_list *list, const char *substr, t_movie *results, int max_results);`  
    Cerca per sottostringa nel genere (case-insensitive).
  - `int filter_by_watched(const t_movie_list *list, int watched_flag, t_movie *results, int max_results);`  
    Filtra per visti/non visti.
  - `int add_movie(t_movie_list *list, const t_movie *new_movie);`  
    Aggiunge un nuovo film (con validazione).
  - `int mark_as_watched(t_movie_list *list, int id, int rating, const char *date_watched);`  
    Segna un film come visto, assegnando voto e data.
  - `int update_movie(t_movie_list *list, int id, const char *new_title, const char *new_genre);`  
    Aggiorna titolo o genere di un film.
  - `int delete_movie(t_movie_list *list, int id);`  
    Elimina un film (con conferma).
  - `void show_summary(const t_movie_list *list);`  
    Mostra statistiche: totale, visti/non visti, media voti, breakdown per genere.

- **Utility e validazione**
  - `char *str_trim(char *str);`  
    Rimuove spazi e newline.
  - `int strcasestr_custom(const char *haystack, const char *needle);`  
    Cerca sottostringa case-insensitive.
  - `int is_valid_date(const char *date);`  
    Verifica formato e plausibilità della data.
  - `int is_unique_id(const t_movie_list *list, int id);`  
    Verifica unicità dell’ID.
  - `void free_movie_list(t_movie_list *list);`  
    Libera la memoria allocata.