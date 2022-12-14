#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float a = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3;
            int b = round(a);
            image[i][j].rgbtBlue = b;
            image[i][j].rgbtRed = b;
            image[i][j].rgbtGreen = b;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a = (0.189 * image[i][j].rgbtBlue) + (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen);
            int b = (0.168 * image[i][j].rgbtBlue) + (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen);
            int c = (0.131 * image[i][j].rgbtBlue) + (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen);

            a = round(a);
            b = round(b);
            c = round(c);

            

            if (a > 255)
            {
                a = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            if (c > 255)
            {
                c = 255;
            }

            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtBlue = c;
            
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE tmp;
        for (int j = 0; j < width; j++)
        {
            while (j < width / 2)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = tmp;
            }

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
