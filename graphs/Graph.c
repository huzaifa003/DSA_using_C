#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct AdjacencyNode
{
    int destination;
    struct AdjacencyNode *next;
} AdjacencyNode;

typedef struct AdjacencyList
{
    AdjacencyNode *head;
} AdjacencyList;

typedef struct Graph
{
    int v;
    AdjacencyList *array;
} Graph;

Graph *createGraph(int v)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->array = malloc(v * sizeof(AdjacencyList)); //array will hold all the heads whose size will be equal to number of vertices (v)
    graph->v = v;

    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL; //making all heads as null
    }

    return graph;
}

AdjacencyNode *createAdjacencyNode(int destination)
{
    AdjacencyNode *newNode = malloc(sizeof(AdjacencyNode));
    newNode->destination = destination;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph *graph, int source, int destination)
{
    AdjacencyNode* iterator = graph->array[source].head;
    AdjacencyNode* newNode = createAdjacencyNode(destination);

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

    newNode = createAdjacencyNode(source);
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

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->v; i++)
    {
        AdjacencyNode* iterator = graph->array[i].head;
        printf("Adjacency List for vertex %d is :\n",i);
        while (iterator != NULL)
        {
            printf("%d->",iterator->destination);
            iterator = iterator->next;
        }
        printf("\n");
    }
}
int main()
{

    Graph* graph = createGraph(3);

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    printGraph(graph);
    getch();

    return 0;
}