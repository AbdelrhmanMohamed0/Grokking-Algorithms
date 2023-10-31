#include <stdio.h>
#include <stdbool.h>

#define INF 9999
#define MAX_NODES 100

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode)
{
    int distance[MAX_NODES];
    bool visited[MAX_NODES];

    for (int i = 0; i < numNodes; i++)
    {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[startNode] = 0;

    for (int count = 0; count < numNodes - 1; count++)
    {
        int minDistance = INF;
        int minNode = -1;

        for (int i = 0; i < numNodes; i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                minNode = i;
            }
        }

        visited[minNode] = true;

        for (int i = 0; i < numNodes; i++)
        {
            if (!visited[i] && graph[minNode][i] != INF)
            {
                int newDistance = distance[minNode] + graph[minNode][i];
                if (newDistance < distance[i])
                {
                    distance[i] = newDistance;
                }
            }
        }
    }

    printf("Shortest distances from node %d:\n", startNode);
    for (int i = 0; i < numNodes; i++)
    {
        printf("To node %d: %d\n", i, distance[i]);
    }
}

int main()
{
    int numNodes, startNode;
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(graph, numNodes, startNode);

    return 0;
}
