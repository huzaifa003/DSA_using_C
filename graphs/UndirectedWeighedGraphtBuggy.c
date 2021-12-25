#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct AdjacencyNode
{
    int weight;
    int destination;
    struct AdjacencyNode *next;
} AdjacencyNode;

typedef struct AdjacencyList
{
    AdjacencyNode *head;
} AdjacencyList;

typedef struct UndirectedWeighedGraph
{
    int v;
    AdjacencyList *array;
} UndirectedWeighedGraph;

UndirectedWeighedGraph *createGraph(int v)
{
    UndirectedWeighedGraph *graph = malloc(sizeof(UndirectedWeighedGraph));
    graph->array = malloc(v * sizeof(AdjacencyList)); //array will hold all the heads whose size will be equal to number of vertices (v)
    graph->v = v;

    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL; //making all heads as null
    }

    return graph;
}

AdjacencyNode *createAdjacencyNode(int destination, int weight)
{
    AdjacencyNode *newNode = malloc(sizeof(AdjacencyNode));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(UndirectedWeighedGraph *graph, int source, int destination, int weight)
{
    AdjacencyNode *iterator = graph->array[source].head;
    AdjacencyNode *newNode = createAdjacencyNode(destination, weight);

    if (graph->array[source].head == NULL)
    {
        graph->array[source].head = newNode;
    }

    else
    {
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }

    //for undirected grpah we add vertex from destination to source as well

    newNode = createAdjacencyNode(source, weight);
    iterator = graph->array[destination].head;

    if (graph->array[destination].head == NULL)
    {
        graph->array[destination].head = newNode;
    }

    else
    {
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }
}

void printGraph(UndirectedWeighedGraph *graph)
{
    for (int i = 0; i < graph->v; i++)
    {
        AdjacencyNode *iterator = graph->array[i].head;
        printf("Adjacency List for vertex %d is :\n", i);
        while (iterator != NULL)
        {
            printf("(%d with weight %d)->", iterator->destination, iterator->weight);
            iterator = iterator->next;
        }
        printf("\n");
    }
}

typedef struct visitedNonVisted
{
    int addedWeight;
    AdjacencyNode *node;
} visitedNonVisited;

int findMinIndex(visitedNonVisited arr[], int size)
{
    int minIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].addedWeight < arr[minIndex].addedWeight)
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void deleteInArray(visitedNonVisited arr[], int index, int *size)
{
    for (int i = index; i < *size - 1; i++)
    {
        arr[index] = arr[index + 1];
    }
    *size = *size - 1;
}

int matchReferences(visitedNonVisited nonVisited[], AdjacencyNode *node, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Destination is = %d\n",nonVisited[i].node->destination);
        if (nonVisited[i].node->destination == node->destination)
        {
            return i;
        }
    }

    printf("\n---------Not Matched------\n");
    return -1;
}

void dijkstra(UndirectedWeighedGraph *graph, int source, int destination)
{
    int tempSize = graph->v;
    visitedNonVisited visted[tempSize];
    visitedNonVisited nonVisted[tempSize];
    int indexVisited = 0;

    for (int i = 0; i < tempSize; i++)
    {
        nonVisted[i].node = graph->array[i].head; //added all the nodes
        nonVisted[i].addedWeight = 9999;          //infinite weight
    }

    AdjacencyNode *iterator;
    for (int i = 0; i < tempSize; i++)
    {
        iterator = nonVisted[i].node;
        printf("iterator %d\n",iterator);
        while (iterator != NULL)
        {
            printf("(%d with weight %d)->", iterator->destination, iterator->weight);
            iterator = iterator->next;
        }

        printf("\n");
    }

    printf("\n\n\n\n-------------------------------------------");

    //initializing the first node;

    AdjacencyNode *temp = graph->array[source].head;
    int index;

    while (temp != NULL)
    {
        printf("Temp is = %d\n",temp->destination);
        index = matchReferences(nonVisted, temp,tempSize);
        visted[index].addedWeight = temp->weight;
        temp = temp->next;
    }
}
int main()
{

    UndirectedWeighedGraph *graph = createGraph(9);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    printGraph(graph);

    printf("------------------------------------\n\n\n\n\n");
    dijkstra(graph, 0, 8);

    getch();

    return 0;
}