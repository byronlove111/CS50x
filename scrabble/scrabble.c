#include <cs50.h>
#include <stdio.h>

void calculatePoints(string word1, string word2);
int len(string word);
int findInAlphabet(char letter);
string toUpperCase(string word);

int main(void)
{
    const int players = 2;
    int i = 0;
    string words[2];
    while (i < players)
    {
        words[i] = get_string("Saissisez un mot : ");
        i++;
    }
    calculatePoints(toUpperCase(words[0]), toUpperCase(words[1]));
    return 0;
}

// Prends les mots des deux jours et renvoi et print le gagnant ou le match nul
void calculatePoints(string word1, string word2)
{
    const int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,
 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int player1Points = 0;
    int player2Points = 0;
    int lengthWord1 = len(word1);
    int lengthWord2 = len(word2);
    int counter1 = 0;
    int counter2 = 0;

    while (counter1 < lengthWord1)
    {
        int pointsLetter;
        int letterNumber = findInAlphabet(word1[counter1]);
        if (letterNumber < 0 || letterNumber > 25)
        {
            pointsLetter = 0;
        }
        else
        {
            pointsLetter = points[letterNumber];
        }
        player1Points += pointsLetter;
        counter1++;
    }

    while (counter2 < lengthWord2)
    {
        int pointsLetter;
        int letterNumber = findInAlphabet(word2[counter2]);
        if (letterNumber < 0 || letterNumber > 25)
        {
            pointsLetter = 0;
        }
        else
        {
            pointsLetter = points[letterNumber];
        }
        player2Points += pointsLetter;
        counter2++;
    }

    if (player1Points > player2Points)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Points > player1Points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calcule la taille d'une array
int len(string word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        i++;
    }
    return i;
}

// cherche l'index du charactere dans l'alphabet et le retourne
int findInAlphabet(char letter)
{
    const char alphabet[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    int counter = 0;
    int index = 0;

    if (letter >= 'A' && letter <= 'Z')
    {
        while(letter != alphabet[counter] && counter < 26)
        {
            counter++;
        }

        if (letter == alphabet[counter])
        {
            index = counter;
        }
        return index;
    }
    return -1;
}

// transforme la string passé en uppercase
string toUpperCase(string word)
{
    int i = 0;
    int length = len(word);

    while (i < length)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
        i++;
    }
    return word;
}
