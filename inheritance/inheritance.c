// Simulate genetic inheritance of blood type

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();
char choose_allele(person *p);

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    person *child = (person *) malloc(sizeof(person));

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        child->parents[0] = parent0;
        child->parents[1] = parent1;

        char first_allele = choose_allele(parent0);
        char second_allele = choose_allele(parent1);

        child->alleles[0] = first_allele;
        child->alleles[1] = second_allele;
    }

    // If there are no generations left to create
    else
    {
        child->parents[0] = NULL;
        child->parents[1] = NULL;

        child->alleles[0] = random_allele();
        child->alleles[1] = random_allele();
    }

    return child;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}

char choose_allele(person *p)
{
    char first_allele = toupper(p->alleles[0]);
    char second_allele =  toupper(p->alleles[1]);

    int r = rand() % 2;

    if (first_allele == 'O' && second_allele != 'O')
    {
        return p->alleles[1];
    }
    else if (first_allele != 'O' && second_allele == 'O')
    {
        return p->alleles[0];
    }
    else if (first_allele == 'O' && second_allele == 'O')
    {
        return p->alleles[0];
    }
    else if (r == 0)
    {
        return p->alleles[0];
    }
    else
    {
        return p->alleles[1];
    }
}
