#include <stdio.h>
#include <stdlib.h>

int *hashTable;
int SIZE;

void init(int size) {
    SIZE = size;
    hashTable = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void rehash(int *count) {
    printf("Rehashing...\n");

    int newSize = SIZE * 2;
    int *newTable = (int *)malloc(newSize * sizeof(int));

    for (int i = 0; i < newSize; i++)
        newTable[i] = -1;

    // Move data from old table to new table
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            int key = hashTable[i];
            int index = key % newSize;

            while (newTable[index] != -1)
                index = (index + 1) % newSize;

            newTable[index] = key;
        }
    }

    // Replace old table with new table
    free(hashTable);
    hashTable = newTable;
    SIZE = newSize;
}
void dis(){
    printf("New table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

void insert(int key, int *count) {
    if (*count >= SIZE * 0.7) {
        rehash(count);
    }

    int index = hash(key);

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
    (*count)++;
}

int main() {
    init(5);

    int count = 0;

    insert(10, &count);
    insert(20, &count);
    insert(30, &count);
    insert(40, &count); // triggers rehash
    insert(50, &count);
    dis();

    return 0;
}

