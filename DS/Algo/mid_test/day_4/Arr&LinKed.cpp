#include <stdio.h>
#include <stdlib.h>
int* ArrayTest(){
    int scores[10];
    scores[0] = 1;
    scores[1] = 2;
    scores[2] = 3;
    return scores;
}

typedef struct node
{
    int data;
    struct node *next;
} Node;
Node* BuildOneTwoThree(){
    Node* head = NULL; Node* second = NULL; Node* third = NULL;
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 1;
    third->next = NULL;
    return head;
}
int Length(Node* head){
    Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;    
}
int main(){
    int *array_ptr;
    int sc[10];
    array_ptr = ArrayTest();
    for (int i = 0; i < 10; i++)
    {
        sc[i]=*(array_ptr + i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",sc[i]);
    }
    getchar();
    Node* list1 = NULL;
    Node* current = NULL;
    list1 = BuildOneTwoThree();
    while (current != NULL)
    {
        printf("<%d, %p>\n", current->data, current->next);
        current = current->next;
    }
    printf("리스트의 길이(노드수): %d\n", Length(list1));
    return 0;
}