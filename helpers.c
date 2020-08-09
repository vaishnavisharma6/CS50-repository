#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.00) ;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int red =  round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);


            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;






        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

     int i;
     int j;
     int k;
     int swap = 0;
      int temp = 0;
      int ex = 0;

    for (i = 0 ; i < height ; i++)
    {
        for(j = 0 , k =  width - 1 ; j <= width / 2 , k >= width / 2 ; j++, k--)
        {
            swap = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtRed = swap;

            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = temp;

            ex = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = ex;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float averageone[height][width];
    float averagetwo[height][width];
    float averagethree[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            if ((i > 0 && i < (height - 1)) && (j > 0 && j < (width - 1)))
            {
                averageone[i][j] = round((image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed
                                     + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 9.00);

                averagetwo [i][j] = round((image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                     image[i + 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 9.00);

                averagethree [i][j] = round((image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen
                                       + image[i + 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 9.00);


            }

            else
            {
                if (i == 0 && (j != 0 || j != (width - 1)))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed
                                         + image[i + 1][j + 1].rgbtRed) / 6.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 6.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.00);

                }

                if (i == 0 && j == 0)
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.00);


                }

                if (i == 0 && j == (width - 1))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.00);

                }

                if (i == (height - 1) && (j != 0 || j != width - 1))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                        image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                        image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen
                                           + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.00);
                }

                if (i == (height - 1) && j == 0)
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 4.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.00);

                }
                if (i == (height - 1) && j == (width - 1))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / 4.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 4.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 4.00);


                }

                if (j == 0  && (i != 0 && i != height - 1))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed
                                         + image[i - 1][j + 1].rgbtRed) / 6.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i+ 1][j + 1].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue) / 6.00) ;
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                          image[i + 1][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.00);

                }

                if (j == width - 1 && (i != 0 && i != height - 1))
                {
                    averageone[i][j] = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i- 1][j - 1].rgbtRed
                                         + image[i][j - 1].rgbtRed) / 6.00);
                    averagetwo[i][j] = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                         image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 6.00);
                    averagethree[i][j] = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen
                                          + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 6.00);
                }

            }

        }
    }

      for (int i = 0 ; i < height ; i++)
      {
          for (int j = 0 ; j < width ; j++)
          {
            if (averageone[i][j] > 255)
              {
                  averageone[i][j] = 255.00 ;
              }
              if (averagetwo[i][j] > 255)
              {
                  averagetwo[i][j] = 255.00;
              }
              if (averagethree[i][j] > 255)
              {
                  averagethree[i][j] = 255.00;
              }
              image[i][j].rgbtRed = averageone[i][j];
              image[i][j].rgbtBlue = averagetwo[i][j];
              image[i][j].rgbtGreen = averagethree[i][j];
          }
      }
    return;
}
