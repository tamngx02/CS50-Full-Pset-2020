#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (int argc, char *argv [])
{
    // getting user input
    char *s;
    s = get_string ("Text: ");
    
    int i, charcount = 0, spacecount = 0, lettercount = 0, other = 0;  //count letters
    int wordcount;  //count words
    int sentence = 0;   //count sentences
    for (i = 0; s[i]; i++)
    {
        if (s[i] != ' ')    //count letters
            charcount ++;
        else
            spacecount ++;
        if ( (s[i] > 64 && s[i] < 90) || (s[i] > 96 && s[i] < 123) )
            lettercount ++;
        else if (s[i] == 32)
            spacecount += 0;
        else
            other ++;
        
        wordcount = spacecount + 1;   // count words

        if (s[i] == 33 || s[i] == 46 || s[i] == 63)     //count sentences
            sentence++;
        else
            sentence +=0;
    }
    
    // Coleman-Liau index
    float L = ((float)lettercount / (float)wordcount ) * 100; //L is the average number of letters per 100 words
    float S = ((float)sentence / (float)wordcount) * 100; //S is the average number of sentences per 100 words
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
        printf ("Before Grade 1\n");
    else if (index > 16)
        printf ("Grade 16+\n");
    else
        printf ("Grade %d\n", (int)round(index));
}
