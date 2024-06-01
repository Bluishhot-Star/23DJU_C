#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char* data;
    struct node *next;
} Node;
typedef struct LinkedList
{
    Node* head;
    int length;
} List;

Node* CreateNodeInstance(char* data){
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;
    return nNode;
}
List* CreateListInstance(){
    List* nList = (List*)malloc(sizeof(List));
    nList->head = NULL;
    nList->length = 0;
    return nList;
}
void Add_Node(List* list, Node* node, int addIndex){
    Node* temp = list->head;

    int index = 0;
    if (temp == NULL)
    {
        list->head = node;
        return;
    }
    while (temp->next != NULL)
    {
        if (index+1 == addIndex) break;
        index++;
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return;
}
void displayList(List* list){
    Node* temp = list->head;
    while(temp != NULL){
        printf("%s ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
Node* findNode(List* list, char* target){
    Node* temp = list->head;
    while (temp->next != NULL)
    {
        if((temp->data) == target) break;
        temp = temp->next;
    }
    return temp;
}
void deleteNode(List* list, char* target){
    Node* cNode = list->head;
    Node* pNode = list->head;
    while (cNode->next != NULL)
    {
        if((cNode->data) == target){
            pNode->next = cNode->next;
            free(cNode);
        };
        pNode = cNode;
        cNode = cNode->next;
    }
}

int main(){
    List* weekList = CreateListInstance();
    Node* n1 = CreateNodeInstance("일"); Add_Node(weekList, n1, 0);
    Node* n2 = CreateNodeInstance("수"); Add_Node(weekList, n2, 1);
    Node* n3 = CreateNodeInstance("월"); Add_Node(weekList, n3, 1);
    displayList(weekList);
    Node* p = findNode(weekList, "수");
    if (p != NULL)
    {
        printf("%s를 찾았습니다\n",p->data);
    }
    deleteNode(weekList, "월");
    displayList(weekList);
    return 0;
}

