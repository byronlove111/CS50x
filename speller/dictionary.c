// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 26;

// declarations useful variables
unsigned int words_count;

// Hash table
node *table[HASHTABLE_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert the word to lowercase for hashing and comparison
    char lower_word[LENGTH + 1];
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[len] = '\0';

    unsigned int index = hash(lower_word);
    node* ptr = table[index];

    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, lower_word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index = 0;
    int counter = 0;

    while(word[counter] != '\0')
    {
        index += (unsigned int)word[counter];
        counter++;
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE* source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Unable to open, %s", dictionary);
        return 1;
    }

    char max_letters[LENGTH + 1];

    while(fscanf(source, "%s", max_letters) != EOF)
    {
        node* line = (node*)malloc(sizeof(node));
        if (line == NULL)
        {
            return 1;
        }

        strcpy(line->word, max_letters);
        unsigned int index = hash(line->word);

        line->next = table[index];
        table[index] = line;

        words_count++;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (words_count > 0)
    {
        return words_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = table[i];

        while (cursor != NULL)
        {
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
