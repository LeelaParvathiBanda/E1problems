#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Define a structure for a dictionary node
struct node {
    char [50]key;
    char value[50];
    struct node *next;
};

// Define a structure for the dictionary
struct dictionary {
    struct node *table[SIZE];
};

// Function to create a new node
struct node* createNode(char key[], char value[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Function to calculate hash value
int hash(char key[]) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

// Function to insert a key-value pair into the dictionary
void insert(struct dictionary *dict, char key[], char value[]) {
    int index = hash(key);
    struct node* newNode = createNode(key, value);
    if (dict->table[index] == NULL) {
        dict->table[index] = newNode;
    } else {
        struct node* temp = dict->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a key in the dictionary and return its value
char* search(struct dictionary *dict, char key[]) {
    int index = hash(key);
    struct node* temp = dict->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct dictionary dict;
    for (int i = 0; i < SIZE; i++) {
        dict.table[i] = NULL;
    }
    
    // Insert key-value pairs into the dictionary
    insert(&dict, "apple", "fruit");
    insert(&dict, "banana", "fruit");
    insert(&dict, "carrot", "vegetable");
    
    // Search for keys in the dictionary
    printf("Value of 'apple': %s\n", search(&dict, "apple"));
    printf("Value of 'banana': %s\n", search(&dict, "banana"));
    printf("Value of 'carrot': %s\n", search(&dict, "carrot"));
    printf("Value of 'potato': %s\n", search(&dict, "potato"));
    
    return 0;
}
