# Expense Tracker - Struttura del file `expense_tracker.h`

## Strutture Dati

- **t_expense**  
  Rappresenta una singola spesa:
  - `date`: data in formato "YYYY-MM-DD"
  - `amount`: importo positivo (>0)
  - `category`: categoria della spesa
  - `description`: descrizione della spesa

- **t_expense_list**  
  Contiene tutte le spese caricate:
  - `expenses`: array di massimo 1000 spese
  - `count`: numero di spese valide

- **t_category_summary**  
  Usata per il riepilogo per categoria:
  - `category`: nome della categoria
  - `total`: totale speso in questa categoria
  - `percentage`: percentuale sul totale
  - `count`: numero di spese in questa categoria

## Prototipi di Funzione

- `int load_expenses(const char *filename, t_expense_list *list);`  
  Carica le spese dal file, saltando e segnalando le righe invalide.

- `int filter_by_category(const t_expense_list *list, const char *substr, t_expense *results, int max_results);`  
  Filtra le spese per categoria (case-insensitive, sottostringa).

- `int filter_by_date_range(const t_expense_list *list, const char *start, const char *end, t_expense *results, int max_results);`  
  Filtra le spese per intervallo di date.

- `void print_summary(const t_expense *expenses, int count);`  
  Mostra il riepilogo: totale, media, breakdown per categoria.

- `void free_expense_list(t_expense_list *list);`  
  Libera la memoria allocata.

- Utility:
  - `char *str_trim(char *str);`  
    Rimuove spazi e newline.
  - `int strcasestr_custom(const char *haystack, const char *needle);`  
    Cerca sottostringa case-insensitive.
  - `int is_valid_date(const char *date);`  
    Verifica formato data.
  - `int compare_dates(const char *date1, const char *date2);`  
    Confronta due date.