#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct QNode
{
    char *person;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};

struct QNode *newNode(char *person)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->person = person;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, char *person)
{
    struct QNode *temp = newNode(person);

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

char *dequeue(struct Queue *q)
{

    if (q->front == NULL)
        return NULL;

    struct QNode *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    char *person = temp->person;

    free(temp);

    return person;
}

bool isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

bool person_is_seller(char *person)
{
    int len = strlen(person);
    return (person[len - 1] == 'm');
}

bool search(char *name)
{

    struct Queue *search_queue = createQueue();
    enqueue(search_queue, name);
    char *searched[100];
    int searched_size = 0;

    while (!isEmpty(search_queue))
    {

        char *person = dequeue(search_queue);

        bool found = false;
        for (int i = 0; i < searched_size; i++)
        {
            if (strcmp(searched[i], person) == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {

            if (person_is_seller(person))
            {
                printf("%s is a mango seller!\n", person);
                return true;
            }
            else
            {

                char *graph[6][4] = {{"you", "alice", "bob", "claire"}, {"bob", "anuj", "peggy", ""}, {"alice", "peggy", "", ""}, {"claire", "thom", "jonny", ""}, {"anuj", "", "", ""}, {"peggy", "", "", ""}};
                int graph_size = 6;

                for (int i = 0; i < graph_size; i++)
                {
                    if (strcmp(graph[i][0], person) == 0)
                    {
                        for (int j = 1; j < 4; j++)
                        {
                            if (strcmp(graph[i][j], "") != 0)
                            {
                                enqueue(search_queue, graph[i][j]);
                            }
                        }
                        break;
                    }
                }

                searched[searched_size] = person;
                searched_size++;
            }
        }
    }
    return false;
}

void test_search(char *name)
{
    printf("Searching for a seller starting from %s...\n", name);
    if (search(name))
    {
        printf("Found a seller!\n");
    }
    else
    {
        printf("No seller found.\n");
    }
}

int main()
{

    test_search("you");
    test_search("bob");
    test_search("claire");
    test_search("anuj");
    return 0;
}