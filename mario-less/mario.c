#include <stdio.h>
#include <cs50.h>

int userInput(void);
void createPyramid(int height);

int main(void)
{
    int n = userInput();
    createPyramid(n);
}

// Récupère un nombre positif et refuse le reste
int userInput(void)
{
    int n = get_int("Height: ");
    while (n <= 0)
    {
      n = get_int("Height: ");
    }
    return n;
}

// Création de la pyramide
void createPyramid(int height)
{
    int counter = 0;
    int espaceBlanc = height - 1;
    int bricks = height - espaceBlanc;

    while (counter < height)
    {
        int counterSpace = 0;
        int counterBricks = 0;

        while (counterSpace < espaceBlanc)
        {
            printf(" ");
            counterSpace++
        }
        while (counterBricks < bricks)
        {
            printf("#");
            counterBricks++;
        }
        bricks++;
        espaceBlanc--;
        counter++;
        printf("\n");
    }
}
