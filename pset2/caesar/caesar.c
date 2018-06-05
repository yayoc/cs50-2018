// Print cyphertext
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        return 1;
    }
    // Cast string to int
    int n = atoi(argv[1]);
    string plain;
    // Prompt for plaintext
    plain = get_string("plaintext: ");
    
    for (int i = 0; i < strlen(plain); i++)
    {
        char c = plain[i];
        if (isalpha(c)) 
        {
            // Get alphabetindex
            int index = 65;
            if (islower(c)) 
            {
                index = index + 32;
            }
            int j = (c - index + n) % 26;
            // Cast to ASCII
            int a = j + index;
            plain[i] = (char) a;
        }
    }
    printf("ciphertext: %s\n", plain);
}
