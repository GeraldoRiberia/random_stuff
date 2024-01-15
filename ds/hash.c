#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    char* key;
    int value;
} Entry;

typedef struct {
    Entry* entries[TABLE_SIZE];
} HashTable;

unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

void initializeTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
}

void insert(HashTable* table, const char* key, int value) {
    unsigned int index = hash(key);

    while (table->entries[index] != NULL) {
        // Linear probing: move to the next slot
        index = (index + 1) % TABLE_SIZE;
    }

    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;

    table->entries[index] = newEntry;
}

int search(HashTable* table, const char* key) {
    unsigned int index = hash(key);

    while (table->entries[index] != NULL) {
        if (strcmp(table->entries[index]->key, key) == 0) {
            return table->entries[index]->value;
        }

        // Linear probing: move to the next slot
        index = (index + 1) % TABLE_SIZE;
    }

    // Key not found
    return -1;
}

void displayTable(HashTable* table) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->entries[i] != NULL) {
            printf("Index %d: Key = %s, Value = %d\n", i, table->entries[i]->key, table->entries[i]->value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    HashTable table;
    initializeTable(&table);

    // Insert entries based on user input
    char key[50];
    int value;

    printf("Insert entries into the hash table. Enter 'exit' as the key to stop.\n");

    while (1) {
        printf("Enter key: ");
        scanf("%s", key);

        if (strcmp(key, "exit") == 0) {
            break;
        }

        printf("Enter value: ");
        scanf("%d", &value);

        insert(&table, key, value);
    }

    // Display the table
    displayTable(&table);

    // Search for entries based on user input
    printf("\nSearch for entries in the hash table. Enter 'exit' as the key to stop.\n");

    while (1) {
        printf("Enter key to search: ");
        scanf("%s", key);

        if (strcmp(key, "exit") == 0) {
            break;
        }

        int result = search(&table, key);
        if (result != -1) {
            printf("Value for key '%s': %d\n", key, result);
        } else {
            printf("Key '%s' not found.\n", key);
        }
    }

    return 0;
}
