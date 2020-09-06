#include "helpers.h"
#include "math.h"
#include "stdio.h"

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
//Check if more than 255
int limit(int rgb){
    if (rgb > 255){
        rgb = 255;
    }
    return rgb;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE copy[height][width];
    int Gx[3][3] = {{-1,0,1}, 
                    {-2,0,2}, 
                    {-1,0,1}
                    };
                    
    int Gy[3][3] = {{-1,-2,-1}, 
                    {0,0,0}, 
                    {1,2,1}
                    };
  
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int GxRed = 0;
            int GyRed = 0;
            int GxGreen = 0; 
            int GyGreen = 0; 
            int GxBlue = 0;
            int GyBlue = 0;
            
            for (int a = 0; a < 3; a++){
                for (int b = 0; b < 3; b++){
                    if (a + i - 1 < 0 || a + i > height || b + j - 1 < 0 || b + j > width){
                        continue;
                    }
                    GxRed += image[i+a-1][j+b-1].rgbtRed * Gx[a][b];
                    GxGreen += image[i+a-1][j+b-1].rgbtGreen * Gx[a][b];
                    GxBlue += image[i+a-1][j+b-1].rgbtBlue * Gx[a][b];
                    
                    GyRed += image[i+a-1][j+b-1].rgbtRed * Gy[a][b];
                    GyGreen += image[i+a-1][j+b-1].rgbtGreen * Gy[a][b];
                    GyBlue += image[i+a-1][j+b-1].rgbtBlue * Gy[a][b];
                }
            }
            float Red = sqrt(GxRed*GxRed + GyRed*GyRed);
            float Green = sqrt(GxGreen*GxGreen + GyGreen*GyGreen);
            float Blue = sqrt(GxBlue*GxBlue + GyBlue*GyBlue);
            copy[i][j].rgbtRed = limit(round(Red));
            copy[i][j].rgbtGreen = limit(round(Green));
            copy[i][j].rgbtBlue = limit(round(Blue));
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
        }
    }
    return;
}
