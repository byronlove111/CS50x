#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int ft_strcmp(string word1, string word2);
int ft_strlen(string word);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name) // 'Bob'
{
    int i = 0;

    while (i < candidate_count)
    {
        if (ft_strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
        else
        {
            i++;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int i = 0;
    int bestScore = 0;
    int findWinner = 0;

    // Find the highest score
    while (i < candidate_count)
    {
        if (bestScore < candidates[i].votes)
        {
            bestScore = candidates[i].votes;
            i++;
        }
        else
        {
            i++;
        }
    }

    while (findWinner < candidate_count)
    {
        if (candidates[findWinner].votes == bestScore)
        {
            printf("%s\n", candidates[findWinner].name);
            findWinner++;
        }
        else
        {
            findWinner++;
        }
    }

    return;
}

// Compare 2 strings, return 0 si identiques, 1 si pas de la meme taille, 2 si caractère différents
int ft_strcmp(string word1, string word2)
{
    int word1len = ft_strlen(word1);
    int word2len = ft_strlen(word2);

    if (word1len != word2len)
    {
        return 1;
    }

    int i = 0;

    while (i < word1len)
    {
        if (word1[i] != word2[i])
        {
            return 2;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

// Calcule la longueur d'une string et renvoi sa length
int ft_strlen(string word)
{
    int i = 0;

    while (word[i] != '\0')
    {
        i++;
    }
    return i;
}
