#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

typedef struct hash_table
{
    node *array[SIZE];
} hash_table;

node *create_node(int key, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

hash_table *create_hash_table()
{
    hash_table *new_table = (hash_table *)malloc(sizeof(hash_table));
    for (int i = 0; i < SIZE; i++)
    {
        new_table->array[i] = NULL;
    }
    return new_table;
}

int hash(int key)
{
    return key % SIZE;
}

void add(hash_table *table, int key, int value)
{
    int index = hash(key);
    node *head = table->array[index];
    node *current = head;
    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }
    node *new_node = create_node(key, value);
    new_node->next = head;
    table->array[index] = new_node;
}

void delete(hash_table *table, int key)
{
    int index = hash(key);
    node *head = table->array[index];
    node *current = head;
    node *previous = NULL;
    while (current != NULL)
    {
        if (current->key == key)
        {
            if (previous == NULL)
            {
                table->array[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int search(hash_table *table, int key)
{
    int index = hash(key);
    node *head = table->array[index];
    node *current = head;
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void print(hash_table *table)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *head = table->array[i];
        node *current = head;
        printf("Index %d: ", i);
        while (current != NULL)
        {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    hash_table *table = create_hash_table();
    add(table, 0, 10);
    add(table, 2, 20);
    add(table, 10, 30);
    add(table, 11, 40);
    add(table, 12, 50);
    print(table);
    printf("Search for key 2: %d\n", search(table, 2));
    printf("Search for key 4: %d\n", search(table, 4));
    delete (table, 2);
    delete (table, 11);
    print(table);
    return 0;
}
