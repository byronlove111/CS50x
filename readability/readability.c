#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Prototypes
string getInput(void);
int len(string array);
int counterLetters(string text);
int counterWords(string text);
int counterSentences(string text);
int colemanFormula(int numberOfLetters, int numberOfWords, int numberOfSentences);
void printGrade(int level);

// Fonction main
int main(void)
{
    string text = getInput();
    int numberOfSentences = counterSentences(text);
    int numberOfWords = counterWords(text);
    int numberOfLetters = counterLetters(text);
    int levelDifficulty = colemanFormula(numberOfLetters, numberOfWords, numberOfSentences);
    printGrade(levelDifficulty);

    return 0;
}

// Return le nombre de lettres dans une string
int counterLetters(string text)
{
    int letters = 0;
    int counter = 0;
    int length = len(text);

    while (counter < length)
    {
        if (text[counter] >= 'a' && text[counter] <= 'z')
        {
            letters++;
            counter++;
        }
        else if (text[counter] >= 'A' && text[counter] <= 'Z')
        {
            letters++;
            counter++;
        }
        else
        {
            counter++;
        }
    }
    return letters;
}

// Return le nombre de mots dans une string
int counterWords(string text)
{
    int counter = 0;
    int words = 0;
    int length = len(text);

    while (counter < length)
    {
        if (text[counter] == ' ')
        {
            words++;
            counter++;
        }
        else
        {
            counter++;
        }
    }
    return words + 1;
}

// Return le nombre de phrases dans une string
int counterSentences(string text)
{
    int counter = 0;
    int sentences = 0;
    int length = len(text);

    while (counter < length)
    {
        if (text[counter] == '?' || text[counter] == '.' || text[counter] == '!')
        {
            sentences++;
            counter++;
        }
        else
        {
            counter++;
        }
    }

    return sentences;
}

// Return le nombre arrondi de la formule Coleman
int colemanFormula(int numberOfLetters, int numberOfWords, int numberOfSentences)
{
    float averageLettersPerWords = ((float) numberOfLetters / (float) numberOfWords) * 100;
    float averageSentencesPerWords = ((float) numberOfSentences / (float) numberOfWords) * 100;
    float index = 0.0588 * averageLettersPerWords - 0.296 * averageSentencesPerWords - 15.8;
    int roundedIndex = (int) round(index);

    return roundedIndex;
}

// Évalue selon la difficulté le grade et le print
void printGrade(int level)
{
    if (level >= 1 && level <= 16)
    {
        printf("Grade %i\n", level);
    }
    else if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// FONCTIONS UTILITAIRES

// Return l'input de l'user en string
string getInput(void)
{
    string input = get_string("Text: ");
    return input;
}

// Return la taille d'une string
int len(string word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        i++;
    }
    return i;
}
