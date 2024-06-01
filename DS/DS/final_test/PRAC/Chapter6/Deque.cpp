#include <stdio.h>
#include <stdlib.h>

typedef int elem;
typedef struct DequeNode
{
    elem data;
    struct DequeNode* left;
    struct DequeNode* right;
}node;

typedef struct Deque
{
    node* front;
    node* rear;
}Deque;

Deque* createDeque()
{
    Deque* DQ = (Deque*)malloc(sizeof(Deque));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

bool DQisEmpty(Deque* DQ)
{
    if(DQ->front==NULL) return true;
    return false;
}

void DQAddFront(Deque* DQ, elem data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(DQisEmpty(DQ))
    {
        DQ->front = newNode;
        DQ->rear = newNode;
    }
    else
    {
        DQ->front->left = newNode;
        newNode->right = DQ->front;
        DQ->front = newNode;
    }
}
void DQAddRear(Deque* DQ, elem data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(DQisEmpty(DQ))
    {
        DQ->front = newNode;
        DQ->rear = newNode;
    }
    else
    {
        DQ->rear->right = newNode;
        newNode->left = DQ->rear;
        DQ->rear = newNode;
    }
}

elem DQRemoveFront(Deque* DQ)
{
    elem temp = -1;
    if(!DQisEmpty(DQ))
    {
        temp = DQ->front->data;
        node* deleteNode = DQ->front;
        DQ->front = DQ->front->right;
        free(deleteNode);
        if(DQisEmpty(DQ))
            DQ->rear = NULL;
    }
    return temp;
}
elem DQRemoveRear(Deque* DQ)
{
    elem temp = -1;
    if(!DQisEmpty(DQ))
    {
        temp = DQ->rear->data;
        node* deleteNode = DQ->rear;
        DQ->rear = DQ->rear->left;
        free(deleteNode);
        DQ->rear->right = NULL;
        if(DQisEmpty(DQ))
            DQ->front = NULL;
    }
    return temp;
}

void printDeque(Deque* DQ)
{
    if(!DQisEmpty(DQ))
    {
        node* temp = DQ->front;
        while (temp != NULL)
        {
            printf("%3d |", temp->data);
            temp = temp->right;
        }
        printf("\n");
    }
}

int main(){
    Deque* DQ = createDeque();
    DQAddFront(DQ,1);
    DQAddFront(DQ,2);
    DQAddFront(DQ,3);
    DQAddRear(DQ,4);
    DQAddRear(DQ,5);
    DQAddRear(DQ,6);
    printDeque(DQ);

    printf("\n=== Remove from Front ===\n");
    printf("%3d \n",DQRemoveFront(DQ));
    printf("\n=== Remove from Rear ===\n");
    printf("%3d \n",DQRemoveRear(DQ));

    printf("\n=== Result ===\n");
    printDeque(DQ);
    return 0;
}