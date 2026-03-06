#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);   // second hash
}

void insert(int key) {
    int index = hash1(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Inserted %d at index %d\n", key, index);
        return;
    }

    int i = 1;
    while (i < SIZE) {
        int newIndex = (index + i * hash2(key)) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();
    return 0;
}
