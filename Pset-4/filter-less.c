#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

//the function to make rgb < 255 to stop overflow
int limit(int rgb){
    if (rgb > 255){
        rgb = 255;
    }
    return rgb;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            image[i][j].rgbtRed = limit(round(0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue));
            image[i][j].rgbtGreen = limit(round(0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue));
            image[i][j].rgbtBlue = limit(round(0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){ //left to right right to left and the center stays the same
            RGBTRIPLE pixel = image[i][j];
            int temp[3];
            temp[0] = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtRed = temp[0];

            temp[1] = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtGreen = temp[1];

            temp[2] = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtBlue = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float numPixel = 0;
            
            for (int a = -1; a < 2; a++){
                if (a + i < 0 || a + i > height-1){//check if it is from the top/bottom edge or corner to the center of the pic, if out then skip and continue
                    continue;
                }
                for (int b = -1; b < 2; b++){ //check if it is from the left/right edge or corner to the center of the pic, if out then skip and continue
                    if (b + j < 0 || b + j > width-1){
                        continue;
                    }
                    sumRed += image[i+a][j+b].rgbtRed;
                    sumGreen += image[i+a][j+b].rgbtGreen;
                    sumBlue += image[i+a][j+b].rgbtBlue;
                    numPixel++;
                }
            }
            temp[i][j].rgbtRed = round(sumRed / numPixel);
            temp[i][j].rgbtGreen = round(sumGreen / numPixel);
            temp[i][j].rgbtBlue = round(sumBlue / numPixel);
        }
    }
    
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    return;
} 
