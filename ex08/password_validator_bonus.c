#include "password_validator.h"

bool check_similar(const char *s, const char *t)
{
    int len_s = ft_strlen(s);
    int len_t = ft_strlen(t);
    bool change = false;

    if (len_s == len_t)
    {
        for (int i = 0; s[i]; i++)
        {
            if (s[i] != t[i])
            {
                if (change)
                    return false;
                change = true;
            }
        }
        return true;
    }
    else if (len_s == len_t + 1)
    {
        for (int j = 0; s[j]; j++)
        {
            if (s[j] != t[j - (int)change])
            {
                if (change)
                    return false;
                change = true;
            }
        }
        return true;
    }
    else if (len_s == len_t - 1)
    {
        for (int k = 0; s[k]; k++)
        {
            if (s[k] != t[k + (int)change])
            {
                if (change)
                    return false;
                change = true;
            }
        }
        return true;
    }
    return false;
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    if (validate_password_weak(new_pw, (*history)[0]) == 1)
        return 1;
    for (int i = 0; i < 3; i++)
    {
        if (check_similar(new_pw, (*history)[i]))
            return 2;
    }
    strncpy((*history)[2], (*history)[1], 1024);
    strncpy((*history)[1], (*history)[0], 1024);
    strncpy((*history)[0], new_pw, 1024);
    return 0;
}

int main(void)
{
    PasswordHistory history = {
        "password123",
        "password124",
        "passw0rd124"
    };

    // Prova alcune password
    const char *test_pw[] = {
        "password123",   // uguale alla 0
        "password124",   // uguale alla 1
        "passwrd",       // debole (non contiene numeri)
        "password1234",  // debole (non contiene lettere maiuscole)
        "Password123",   // debole (non contiene caratteri speciali)
        "password125",   // simile (1 char diverso)
        "password12",    // simile (1 char in meno)
        "password1234",  // simile (1 char in più)
        "NuovaPass1^",   // nuova, forte, diversa
        "NuovaPass2^",   // simile alla precedente (1 char diverso)
        NULL
    };

    for (int i = 0; test_pw[i]; i++)
    {
        PwStatus res = validate_password(test_pw[i], (PasswordHistory *)&history);
        printf("Test \"%s\": ", test_pw[i]);
        if (res == 0)
            printf("OK (password accettata)\n");
        else if (res == 1)
            printf("Password debole\n");
        else if (res == 2)
            printf("Password troppo simile a una precedente\n");
        else
            printf("Errore sconosciuto\n");
    }

    return 0;
}