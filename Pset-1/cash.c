#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){
    int cents;
    do{
        float cash = get_float("Change owed: ");
        cents = round(cash * 100);
    }
    while (cents < 0);
    
    int quarters = floor(cents / 25);
    int dimes = floor((cents % 25) / 10);
    int nickels = floor(((cents % 25) % 10) / 5);
    int pennies = floor(((cents % 25) % 10) % 5);
    
    int sum = quarters + dimes + nickels + pennies;
    printf("%d\n", sum);
}
