#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int compteurRangee = 0;
    while (compteurRangee < height)
    {
        int compteurColonnes = 0;
        while (compteurColonnes < width)
        {
            int averageShade = round((float) (image[compteurRangee][compteurColonnes].rgbtBlue + image[compteurRangee][compteurColonnes].rgbtGreen + image[compteurRangee][compteurColonnes].rgbtRed) / 3);

            image[compteurRangee][compteurColonnes].rgbtRed = averageShade;
            image[compteurRangee][compteurColonnes].rgbtGreen = averageShade;
            image[compteurRangee][compteurColonnes].rgbtBlue = averageShade;
            compteurColonnes++;
        }
        compteurRangee++;
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int compteurRangee = 0;
    while (compteurRangee < height)
    {
        int compteurColonnes = 0;
        while (compteurColonnes < width)
        {
            int originalRed = image[compteurRangee][compteurColonnes].rgbtRed;
            int originalGreen = image[compteurRangee][compteurColonnes].rgbtGreen;
            int originalBlue = image[compteurRangee][compteurColonnes].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[compteurRangee][compteurColonnes].rgbtRed = sepiaRed;
            image[compteurRangee][compteurColonnes].rgbtGreen = sepiaGreen;
            image[compteurRangee][compteurColonnes].rgbtBlue = sepiaBlue;

            compteurColonnes++;
        }
        compteurRangee++;
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int compteurRangee = 0;
    while (compteurRangee < height)
    {
        int compteurColonnes = 0;
        int median = width / 2;

        while (compteurColonnes < median)
        {
            RGBTRIPLE temp = image[compteurRangee][compteurColonnes];
            image[compteurRangee][compteurColonnes] =
                image[compteurRangee][width - compteurColonnes - 1];
            image[compteurRangee][width - compteurColonnes - 1] = temp;
            compteurColonnes++;
        }

        compteurRangee++;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_blur[height][width];
    double avgRed, avgGreen, avgBlue;
    float counter;

    // cycle rows
    for (int i = 0; i < height; i++)
    {
        // cycle columns
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;

            // cycle rows within 9 cell square
            for (int s = -1; s < 2; s++)
            {
                // cycle columns within 9 cell square
                for (int n = -1; n < 2; n++)
                {
                    // work only with cells that exist
                    int d = i + s;
                    int k = j + n;

                    if (d < height && k < width && d >= 0 && k >= 0)
                    {

                        avgRed = avgRed + image[d][k].rgbtRed;
                        avgGreen = avgGreen + image[d][k].rgbtGreen;
                        avgBlue = avgBlue + image[d][k].rgbtBlue;

                        // count existing cells within 9 cell square
                        counter++;
                    }
                }
            }

            // Find average value and round floats to nearest integer
            avgRed = round(avgRed / counter);
            avgGreen = round(avgGreen / counter);
            avgBlue = round(avgBlue / counter);

            // Update blured image array with average values
            image_blur[i][j].rgbtRed = avgRed;
            image_blur[i][j].rgbtGreen = avgGreen;
            image_blur[i][j].rgbtBlue = avgBlue;
        }
    }

    // overwrite the variable image with blured image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_blur[i][j];
        }
    }

    return;
}
