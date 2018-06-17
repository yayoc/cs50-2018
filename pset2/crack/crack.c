// Crack password
#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        return 1;
    }

    string hashed = argv[1];
    char salt[2];
    salt[0] = hashed[0];
    salt[1] = hashed[1]; 
    char raw[5];
    char *alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabets_len = strlen(alphabets);

    for (int i = 0; i < alphabets_len; i++) 
    {
        raw[0] = alphabets[i];
        printf("%s\n", crypt(raw, salt));
        if (strcmp(hashed, crypt(raw, salt)) == 0) 
        {
            break; 
        }
        for (int j = 0; j < alphabets_len; j++) 
        {
            raw[1] = alphabets[j];
            printf("%s\n", crypt(raw, salt));
            if (strcmp(hashed, crypt(raw, salt)) == 0) 
            {
                break; 
            }
            for (int k = 0; k < alphabets_len; k++) 
            {
                raw[2] = alphabets[k];
                printf("%s\n", crypt(raw, salt));
                if (strcmp(hashed, crypt(raw, salt)) == 0) 
                {
                    break; 
                }
                for (int l = 0; l < alphabets_len; l++) 
                {
                    raw[3] = alphabets[l];
                    printf("%s\n", crypt(raw, salt));
                    if (strcmp(hashed, crypt(raw, salt)) == 0) 
                    {
                        break; 
                    }
                    for (int m = 0; m < alphabets_len; m++) 
                    {
                        raw[4] = alphabets[m];
                        printf("%s\n", crypt(raw, salt));
                        if (strcmp(hashed, crypt(raw, salt)) == 0) 
                        {
                            break; 
                        }
                    }
                }
            }
        }
    }
    printf("%s\n", raw);
}


