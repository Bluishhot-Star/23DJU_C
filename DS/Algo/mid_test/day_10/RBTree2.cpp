#include <stdio.h>
#include <stdlib.h>

typedef int element;
enum Color { RED, BLACK };
typedef struct RBTreeNode {
	struct RBTreeNode* parent;
	struct RBTreeNode* left;
	struct RBTreeNode* right;
	Color color;
	element data;
} Node;

Node* Nil;

Node* createnode(element newdata)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = newdata;
	newnode->color = BLACK;
	return newnode;
}

void destroynode(Node* node)
{
	free(node);
}

void destroytree(Node* tree)
{
	if (tree->right != Nil)
		destroytree(tree->right);
	if (tree->left != Nil)
		destroytree(tree->left);
	tree->left = Nil;
	tree->right = Nil;
	destroynode(tree);
}

Node* searchnode(Node* tree, element target)
{
	if (tree == Nil)
		return NULL;
	if (tree->data > target)
		return searchnode(tree->left, target);
	else if (tree->data < target)
		return searchnode(tree->right, target);
	else
		return tree;
}

Node* searchminnode(Node* tree)
{
	if (tree == Nil)
		return Nil;
	if (tree->left == Nil)
		return tree;
	else
		return searchminnode(tree->left);
}

void insertnodehelper(Node** tree, Node* newnode)
{
	if (*tree == NULL)
		*tree = newnode;
	if ((*tree)->data < newnode->data) {
		if ((*tree)->right == Nil) {
			(*tree)->right = newnode;
			newnode->parent = *tree;
		}
		else {
			insertnodehelper(&(*tree)->right, newnode);
		}
	}
	else if ((*tree)->data > newnode->data) {
		if ((*tree)->left == Nil) {
			(*tree)->left = newnode;
			newnode->parent = *tree;
		}
		else {
			insertnodehelper(&(*tree)->left, newnode);
		}
	}
}

void rotateright(Node** root, Node* parent)
{
	Node* leftchild = parent->left;
	parent->left = leftchild->right;

	if (leftchild->right != Nil)
		leftchild->right->parent = parent;
	leftchild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = leftchild;
	else {
		if (parent == parent->parent->left)
			parent->parent->left = leftchild;
		else
			parent->parent->right = leftchild;
	}
	leftchild->right = parent;
	parent->parent = leftchild;
}

void rotateleft(Node** root, Node* parent)
{
	Node* rightchild = parent->right;
	parent->right = rightchild->left;

	if (rightchild->left != Nil)
		rightchild->left->parent = parent;
	rightchild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = rightchild;
	else {
		if (parent == parent->parent->left)
			parent->parent->left = rightchild;
		else
			parent->parent->right = rightchild;
	}
	rightchild->left = parent;
	parent->parent = rightchild;
}

void rebuildafterinsert(Node** root, Node* X)
{
	while (X != (*root) && X->parent->color == RED) {
		if (X->parent == X->parent->parent->left) {
			Node* uncle = X->parent->parent->right;
			if (uncle->color == RED) {
				X->parent->color = BLACK;
				uncle->color = BLACK;
				X->parent->parent->color = RED;
				X = X->parent->parent;
			}
			else {
				if (X == X->parent->right) {
					X = X->parent;
					rotateleft(root, X);
				}
				X->parent->color = BLACK;
				X->parent->parent->color = RED;
				rotateright(root, X->parent->parent);
			}
		}
		else {
			Node* uncle = X->parent->parent->left;
			if (uncle->color == RED) {
				X->parent->color = BLACK;
				uncle->color = BLACK;
				X->parent->parent->color = RED;
				X = X->parent->parent;
			}
			else {
				if (X == X->parent->left) {
					X = X->parent;
					rotateright(root, X);
				}
				X->parent->color = BLACK;
				X->parent->parent->color = RED;
				rotateleft(root, X->parent->parent);
			}
		}
	}
	(*root)->color = BLACK;
}

void insertnode(Node** tree, Node* newnode)
{
	insertnodehelper(tree, newnode);
	newnode->color = RED;
	newnode->left = Nil;
	newnode->right = Nil;
	rebuildafterinsert(tree, newnode);
}

void rebuildafterremove(Node** root, Node* successor)
{
	Node* sibling = NULL;
	while (successor->parent != NULL && successor->color == BLACK) {
		if (successor == successor->parent->left) {
			sibling = successor->parent->right;
			if (sibling->color == RED) {
				sibling->color = BLACK;
				successor->parent->color = RED;
				rotateleft(root, successor->parent);
			}
			else {
				if (sibling->left->color == BLACK &&
					sibling->right->color == BLACK) {
					sibling->color = RED;
					successor = successor->parent;
				}
				else {
					if (sibling->left->color == RED) {
						sibling->left->color = BLACK;
						sibling->color = RED;
						rotateright(root, sibling);
						sibling = successor->parent->right;
					}
					sibling->color = successor->parent->color;
					successor->parent->color = BLACK;
					sibling->right->color = BLACK;
					rotateleft(root, successor->parent);
					successor = *root;
				}
			}
		}
		else {
			sibling = successor->parent->left;
			if (sibling->color == RED) {
				sibling->color = BLACK;
				successor->parent->color = RED;
				rotateright(root, successor->parent);
			}
			else {
				if (sibling->right->color == RED) {
					sibling->right->color = BLACK;
					sibling->color = RED;
					rotateleft(root, sibling);
					sibling = successor->parent->left;
				}
				else {
					if (sibling->right->color == RED) {
						sibling->right->color = BLACK;
						sibling->color = RED;
						rotateleft(root, sibling);
						sibling = successor->parent->left;
					}
					sibling->color = successor->parent->color;
					successor->parent->color = BLACK;
					sibling->left->color = BLACK;
					rotateright(root, successor->parent);
					successor = *root;
				}
			}
		}
	}
	successor->color = BLACK;
}

Node* removenode(Node** root, element data)
{
	Node* removed = NULL;
	Node* successor = NULL;
	Node* target = searchnode((*root), data);

	if (target == NULL)
		return NULL;
	if (target->left == Nil || target->right == Nil)
		removed = target;
	else {
		removed = searchminnode(target->right);
		target->data = removed->data;
	}

	if (removed->left != Nil)
		successor = removed->left;
	else
		successor = removed->right;

	successor->parent = removed->parent;
	if (removed->parent == NULL)
		(*root) = successor;
	else {
		if (removed == removed->parent->left)
			removed->parent->left = successor;
		else
			removed->parent->right = successor;
	}

	if (removed->color == BLACK)
		rebuildafterremove(root, successor);

	return removed;
}

void printtree(Node* node, int depth, int blackcount)
{
	int i = 0;
	char c = 'X';
	int v = -1;
	char count[100];

	if (node == NULL || node == Nil)
		return;
	if (node->color == BLACK)
		blackcount++;
	if (node->parent != NULL) {
		v = node->parent->data;
		if (node->parent->left == node)
			c = 'L';
		else
			c = 'R';
	}

	if (node->left == Nil && node->right == Nil)
		sprintf(count, "------- %d", blackcount);
	else
		sprintf(count, "");

	for (i = 0; i < depth; i++)
		printf("   ");
	printf("%d %s [%c, %d] %s\n", node->data,
		(node->color == RED) ? "RED" : "BLACK", c, v, count);
	printtree(node->left, depth + 1, blackcount);
	printtree(node->right, depth + 1, blackcount);
}

int main(void)
{
	Node* tree = NULL;
	Node* node = NULL;

	Nil = createnode(0);
	Nil->color = BLACK;

	while (1) {
		int cmd = 0;	int param = 0;
		char buffer[10];
		printf("Enter command number :\n");
		printf("(1)create a node, (2)remove a node, (3)search a node\n");
		printf("(4)display tree, (5)quit\n");
		printf("cmd number:");
		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &cmd);
		if (cmd < 1 || cmd > 5) {
			printf("Invalid cmd number.\n");	continue;
		}
		else if (cmd == 4) {
			printtree(tree, 0, 0);	printf("\n");	continue;
		}
		else if (cmd == 5) {
			break;
		}
		printf("Enter parameter (1~200) :\n");
		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &param);
		if (param < 1 || param > 200) {
			printf("Invalid parameter.%d\n", param);	continue;
		}
		switch (cmd) {
		case 1:
			insertnode(&tree, createnode(param));	break;
		case 2:
			node = removenode(&tree, param);
			if (node == NULL)	printf("Not found node to delete:%d\n", param);
			else destroynode(node);	break;
		case 3:
			node = searchnode(tree, param);
			if (node == NULL) printf("Not found node:%d\n", param);
			else
				printf("Found node: %d(color:%s)\n", node->data,
					(node->color == RED) ? "RED" : "BLACK");
			break;
		}
		printf("\n");
	}
	destroynode(tree);
	return 0;
}