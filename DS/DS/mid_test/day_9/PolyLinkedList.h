typedef struct ListNode {
    float coef;
    int expo;
    struct ListNode* link;
}listnode;

typedef struct ListHead
{
    int nodeCount;
    listnode* head;
} listhead;

listhead* createLinkedList(void);
void appendTerm(listhead* L, float coef, int expo);
listhead* addPoly(listhead* A, listhead* B);
void printPoly(listhead* L);
void insertTerm(listhead* L, float coef, int expo);
void ReleaseList(listhead* L);
