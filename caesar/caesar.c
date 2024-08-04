#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int checkDigit(string text);
int checkString(string text);
int len(string text);
string cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (checkDigit(argv[1]) != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // string to int via atoi function
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Renvoi 0 si la string en contient que des nombres
int checkDigit(string text)
{
    int counter = 0;
    int length = len(text);
    while (counter < length)
    {
        if (isdigit(text[counter]))
        {
            counter++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// Renvoi 0 si la string en contient que des lettres
int checkString(string text)
{
    int counter = 0;
    int length = len(text);
    while (counter < length)
    {
        if (isalpha(text[counter]))
        {
            counter++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// applique le chiffrement césar sur une string selon la key
string cipher(string plaintext, int key)
{
    int counter = 0;
    int length = len(plaintext);

    while (counter < length)
    {
        if (plaintext[counter] >= 'a' && plaintext[counter] <= 'z')
        {
            plaintext[counter] = 'a' + (plaintext[counter] - 'a' + key) % 26;
            counter++;
        }
        else if (plaintext[counter] >= 'A' && plaintext[counter] <= 'Z')
        {
            plaintext[counter] = 'A' + (plaintext[counter] - 'A' + key) % 26;
            counter++;
        }
        else
        {
            counter++;
        }
    }
    return plaintext;
}

// FONCTIONS UTILITAIRES
int len(string text)
{
    int counter = 0;

    while (text[counter] != '\0')
    {
        counter++;
    }

    return counter;
}
