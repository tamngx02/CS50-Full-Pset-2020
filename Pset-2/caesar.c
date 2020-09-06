#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // if there is only one command and the key is a number
    if (argc == 2 && isdigit(*argv[1]))
    {
        int k = atoi(argv[1]); //turn the key into integer
        if (k < 0) // check if the key is non-negative integer
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // caesar ci = (pi + k) % 26
            // if lower a = 97 then ((s[i] + k) - 97) % 26) + 97)
            // if upper A = 65 then ((s[i] + k) - 65) % 26) + 65)
            string s = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (islower(s[i]))
                {
                    printf("%c", (((s[i] + k) - 97) % 26) + 97);
                }
                else if (isupper(s[i]))
                {
                    printf("%c", (((s[i] + k) - 65) % 26) + 65);
                }
                else
                {
                    printf("%c", s[i]); //if the character is neither uppercase nor lowercase then keep it as it is
                }
            }
        printf("\n");
        return 0;
        }    
    }

    // if it is not 1 command or not the number then error message
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
