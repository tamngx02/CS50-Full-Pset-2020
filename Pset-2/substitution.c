#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string c;
    // if there are two commands or no command => error message
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // if there is only one command 
    else 
    {
        //if the key contains non-alphabetic character => error message
        int n = strlen(argv[1]);
        for (int i = 0; i < n; i++) 
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        
        //if the key doesn't have 26 characters => error message
        if (n != 26)
        {
            printf("Key must contain 26 characters.\n"); 
            return 1;
        }
        
        //if there is repeated character in the key => error message
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; argv[1][j] != '\0'; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    r++;
                }
            }
        }
        if (r != n)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        //promt the user for the plaintext
        string p = get_string("plaintext: "); //p = plaintext
        c = p;
        int key;

        //convert plaintext to ciphertext
        for (int i = 0, len = strlen(p); i < len; ++i)
        {
            if (p[i] >= 'a' && p[i] <= 'z')
            {
                key = p[i] - 'a';
                c[i] = tolower(argv[1][key]);
            }
            else if (p[i] >= 'A' && p[i] <= 'Z')
            {
                key = p[i] - 'A';
                c[i] = toupper(argv[1][key]);
            }
            else 
            {
                c[i] = p[i];
            }
        }
    }
    printf("ciphertext: %s\n", c);
    return 0;

}
