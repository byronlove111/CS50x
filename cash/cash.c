#include <cs50.h>
#include <stdio.h>

int input(void);
int change(int);

int main(void)
{
    int amount = input();
    int nbDePieces = change(amount);
    printf("%i\n", nbDePieces);
}

// Récupère le montant de l'utilisateur
int input(void)
{
    int input = get_int("Change owed: ");
    while (input < 0)
    {
        input = get_int("Change owed: ");
    }
    return input;
}

// Renvoi le nombre de pièces nécessaires pour rendre la monnaie
int change(int amount)
{
    int counter = 0;

    while (amount >= 25)
    {
        counter++;
        amount -= 25;
    }

    while (amount >= 10)
    {
        counter++;
        amount -= 10;
    }

    while (amount >= 5)
    {
        counter++;
        amount -= 5;
    }

    while (amount >= 1)
    {
        counter++;
        amount -= 1;
    }
    return counter;
}
