#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

int main(){
    Node* tree = NULL;
    Node* node = NULL;

    while (1)
    {
        int cmd = 0; int param = 0;
        char buffer[10];
        printf("Enter command number :\n");
        printf("(1)create a note, (2)remove a node, (3)search  a node\n");
        printf("(4)display tree, (5)quit\n");
        printf("cmd number:");
        fgets(buffer, sizeof(buffer) - 1, stdin);
        sscanf(buffer, "%d", &cmd);
        if(cmd < 1 || cmd > 5){ printf("Invaild cmd number\n"); continue; }
        else if (cmd == 4){printTree(tree); printf("\n"); continue; }
        else if (cmd == 5) break;

        printf("Enter parameter (1~200) :\n");
        fgets(buffer, sizeof(buffer)-1, stdin);
        sscanf(buffer, "%d", &param);
        if (param < 1 || param > 200){ printf("Invalid parameter.%d\n", param); continue; }
        switch (cmd)
        {
        case 1:
            insertNode(&tree, createNode(param)); break;
        case 2:
            node = removeNode(&tree, param);
            if (node == NULL) printf("Not found node to delete:%d\n",param);
            else destroyNode(node); break;
        case 3:
            node = searchNode(tree, param);
            if (node == NULL) printf("Not found node:%d\n",param);
            else printf("Found node: %d(color:%s)\n", node->data, (node->color == RED)?"RED":"BLACK");
            break;
        default:
            break;
        }
        printf("\n");
    }
    destroyTree(tree);
    return 0;
}
