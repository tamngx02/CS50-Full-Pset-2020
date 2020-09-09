#include <stdio.h>

int get_int();

int main (void){
    int n = get_int();
    //build the nested loop to draw the pyramid
    
    //build the row
    for (int i = 0; i < n; i++){
        //build the column, at the end of each line will also create the right-aligned
        //right part of the pyramid
        for (int j = 0; j < n + 3 + i; j++){
            //make the space in the left part of the pyramid
            //make the left part right aligned
            if (j < n - i - 1){
                printf(" ");
            }
            //after making the space of the left, created the gap and create the right part
            else{
                //create the gap
                //if the height is an odd number, we need to change to n+1 and n+2 to the space
                //so it is in the center
                if (n % 10 == 1){
                    if (j == n + 2 || j == n + 1){
                        printf(" ");
                        continue;
                    }
                }
                //if height is the even number, change to n and n+1 to the space in the center
                else{
                    if (j == n + 1 || j == n){
                        printf(" ");
                        continue;
                    }
                }
                printf("#");
            }
        }
        printf("\n");
    }   
}

//get the height function
//keep asking for the input until we have the height between 1 and 8
int get_int(){
    int n;
    do{
        printf("Height: ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 8);
    return n;
}
