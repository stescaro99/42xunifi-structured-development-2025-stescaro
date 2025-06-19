# Community Digital Library - Struttura del file `library.h`

## Strutture Dati

- **t_book**  
  Rappresenta un singolo libro, con:
  - `id`: identificatore numerico del libro
  - `title`: titolo del libro
  - `author`: autore del libro

- **t_catalog**  
  Rappresenta il catalogo della libreria, con:
  - `books`: array di massimo 1000 libri (`t_book`)
  - `count`: numero di libri effettivamente caricati

## Prototipi di Funzione

- `int load_catalog(const char *filename, t_catalog *catalog);`  
  Carica i libri dal file specificato nel catalogo, gestendo eventuali righe malformate.

- `int search_by_title(const t_catalog *catalog, const char *substr, t_book *results, int max_results);`  
  Cerca libri il cui titolo contiene la sottostringa data (case-insensitive).

- `int search_by_author(const t_catalog *catalog, const char *substr, t_book *results, int max_results);`  
  Cerca libri il cui autore contiene la sottostringa data (case-insensitive).

- `void print_book(const t_book *book);`  
  Stampa le informazioni di un libro.

- `void free_catalog(t_catalog *catalog);`  
  Libera la memoria eventualmente allocata per il catalogo.

- `char *str_trim(char *str);`  
  Rimuove spazi e newline iniziali/finali da una stringa.

- `int strcasestr_custom(const char *haystack, const char *needle);`  
  Cerca una sottostringa in modo case-insensitive.