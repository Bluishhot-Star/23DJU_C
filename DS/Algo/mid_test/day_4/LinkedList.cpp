#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct LinkedList
{
    Node* head;
    int length;
} List;

Node* CreateNodeInstance(int data){
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = 0;
    nNode->next = NULL;
    return nNode;
}
List* CreateListInstance(){
    List* nList = (List*)malloc(sizeof(List));
    nList->head = NULL;
    nList->length = 0;
    return nList;
}
void Add_Node(List* list, Node* node){
    Node* temp = list->head;
    if (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}
