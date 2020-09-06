// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "strings.h"
#include "ctype.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // Creates copy of word on which hash function can be performed
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
        {
            word_copy[i] = tolower(word[i]);
        }
        
    // Adds null terminator to end string
    word_copy[n] = '\0';
    //Hash the word to obtain the hash value
    int index = hash(word_copy);
    if (table[index]  == NULL){
        return false;
    }
    
    //declare a variable to access the linked list at that index
    node *cursor = table[index];
    
    while(cursor != NULL){
        if(strcasecmp(cursor->word, word_copy) == 0){
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int sum = 0;
    for (int i = 0; i < strlen(word); i++){
        sum += tolower(word[i]);
    }
    return (sum % N);
}

//initialize the counter to 0 for size()
int count = 0;
    
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open the dictionary
    FILE *file = fopen(dictionary, "r");
    
        //check if dictionary cannot be opened
    if (file == NULL){
        return false;
    }
    
    // Create an array of characters to hold each word
    char word[LENGTH + 1];

    //read the dictionary until it reaches the end
    while (fscanf(file, "%s", word) != EOF){
        
        //create a new node
        node *new_node = malloc(sizeof(node));
        memset(new_node, 0, sizeof(node));
        
        if (new_node == NULL){
            return false;
        }
        
        //copy the string to the new node
        strcpy(new_node->word, word);
        
        //hash word
        int head = hash(word);
        
        //insert node into hash table
        //if the new node is the end of the hash table
        if(table[head] == NULL){
            table[head] = new_node;
        }
        //if the new node is not at the end, we need to set the next new node pointer 
        //to the location of the next word, then we relocate the pointer to the next node
        else{
            new_node->next = table[head];
            table[head] = new_node;
        }
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++){
        if (table[i] != NULL){
            node *head = table[i];
            node *cursor = head;
            node *tmp = head;
            
            while(cursor != NULL){
                cursor = cursor->next;
                free(tmp);
                tmp = cursor;
            }
        }
    }
    return true;
}
