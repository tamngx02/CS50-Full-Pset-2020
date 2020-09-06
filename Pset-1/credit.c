#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    //prompt the user for input
    long n;
    do 
    {
        n = get_long ("Number: ");
    }   while ((n < 12) && (n > 16));

    // check the length and the first digits
    int len, f, fd; //len = length; f = first digit; fd = 2 first digits
    len = (int)log10(n);
    f = (int)(n / pow(10, len));
    fd = (int)(n / pow(10, len - 1));
    
    //checksum
    int s1, r1; // s = sum; r = remainder
    s1 = 0;
    int r2, i, r3, s2 = 0, s3 = 0; // r2 = remainder; i = value of the digits multiplied by 2; r3 = remainder of the digits like 5,6,7 when *2 have to digits; s2 = sum 
                                 // s3 = sum of the digits like 5,6,7
    while (n != 0)
    {
        r1 = n % 10;
        s1 = s1 + r1;
        r2 = (n/10) % 10;
        i = r2 * 2;
        
            if (i >= 10)
                while (i != 0)
                {
                    r3 = i % 10;
                    s3 = s3 + r3;
                    i = i / 10;
                }
            else
                s3 = i;

        s2 = s2 + s3;
        n = n / 100;
    }
    
    int j; //j = the last digit of the sum
    j = ((s1 + s2) % 10);
    
    if ((f == 4) && (j == 0))
        printf ("VISA\n");
    else if ((f != 4) && (fd == 34 || fd == 37) && (j == 0))
        printf ("AMEX\n");
    else if ((f != 4) && (fd == 51 || fd == 52 || fd == 53 || fd == 54 || fd ==55) && (j == 0))
        printf ("MASTERCARD\n");
    else
        printf ("INVALID\n");
}
