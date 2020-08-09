#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include "dictionary.h"
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 65536

// define struct node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// declare words to count the words in the dictionary
int dic_size = 0;
// declare hashtable
node *table[HASHTABLE_SIZE];

// hash funtion
unsigned int hash(const char *word)
{
    unsigned int hash1 = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        hash1 = (hash1 << 2) ^ word[i];
    return hash1 % HASHTABLE_SIZE;
}

bool check(const char *word)
{
    int len = strlen(word);
    char lword[len + 1];
    for (int i = 0; i < len; i++)
    {
        lword[i] = tolower(word[i]);
    }
    lword[len] = '\0';

    int bucket = hash(lword);
    node *cursor = table[bucket];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, lword) != 0)
            cursor = cursor->next;
        else
            return true;
    }
    return false;
}

bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        fprintf(stderr, "Cound not open %s.\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(dic, "%s", buffer) != EOF)
    {
        // create a temporary node
        node *temp = malloc(sizeof(node));

        strncpy(temp->word, buffer, sizeof(buffer));

        // implement hash function to get the index
        int index = hash(buffer);

        // if the corresponding index in hashtable is empty, assign it to the temp node
        if (table[index] == NULL)
            table[index] = temp;

        // else append temp to the start of the linked list
        else
        {
            temp->next = table[index];
            table[index] = temp;
        }
        dic_size ++;
    }
    fclose(dic);
    return true;
}

unsigned int size(void)
{
    return dic_size;
}

void destroy(node *head)
{
    if (head->next != NULL)
    {
        destroy(head->next);
    }
    free(head);
}


bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        if (table[i] != NULL)
        {
            destroy(table[i]);
        }
    }
    return true;
}
