# Contact Manager - Struttura del file `contact_manager.h`

## Strutture Dati

- **t_contact**  
  Rappresenta un singolo contatto:
  - `id`: identificatore numerico del contatto
  - `name`: nome
  - `phone`: numero di telefono
  - `email`: indirizzo email valido
  - `city`: città
  - `address`: indirizzo

- **t_contact_list**  
  Contiene tutti i contatti caricati:
  - `contacts`: array di massimo 1000 contatti
  - `count`: numero di contatti validi
  - `max_id`: ID massimo presente

## Prototipi di Funzione

- **Caricamento e salvataggio**
  - `int load_contacts(const char *filename, t_contact_list *list);`  
    Carica i contatti dal file CSV, saltando e segnalando le righe invalide.
  - `int save_contacts(const char *filename, const t_contact_list *list);`  
    Salva tutti i contatti su file

- **Operazioni principali**
  - `void list_contacts(const t_contact_list *list);`  
    Elenca tutti i contatti.
  - `int search_by_name(const t_contact_list *list, const char *substr, t_contact *results, int max_results);`  
    Cerca per sottostringa nel nome (case-insensitive).
  - `int search_by_city(const t_contact_list *list, const char *substr, t_contact *results, int max_results);`  
    Cerca per sottostringa nella città (case-insensitive).
  - `int add_contact(t_contact_list *list, const t_contact *new_contact);`  
    Aggiunge un nuovo contatto (con validazione).
  - `int update_contact(t_contact_list *list, int id, const t_contact *updated_contact);`  
    Aggiorna un contatto esistente tramite ID.
  - `int delete_contact(t_contact_list *list, int id);`  
    Elimina un contatto tramite ID.

- **Utility e validazione**
  - `char *str_trim(char *str);`  
    Rimuove spazi e newline.
  - `int strcasestr_custom(const char *haystack, const char *needle);`  
    Cerca sottostringa case-insensitive.
  - `int is_valid_email(const char *email);`  
    Verifica formato email.
  - `int is_valid_phone(const char *phone);`  
    Verifica formato telefono.
  - `int is_unique_id(const t_contact_list *list, int id);`  
    Verifica unicità dell’ID.
  - `void free_contact_list(t_contact_list *list);`  
    Libera la memoria allocata.