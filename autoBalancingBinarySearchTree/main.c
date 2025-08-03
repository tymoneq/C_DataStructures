#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *leftSon;
    struct Node *rightSon;
    int height;

} Node;

// utility functions
static inline int getHeight(Node *n)
{
    return n ? n->height : 0;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int uptHeight(Node *n)
{
    return max(getHeight(n->leftSon), getHeight(n->rightSon)) + 1;
}
static inline int getBalance(Node *n)
{
    return n ? getHeight(n->leftSon) - getHeight(n->rightSon) : 0;
}

// AVL tree
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = val;
    newNode->height = 1;
    newNode->leftSon = newNode->rightSon = NULL;

    return newNode;
};

Node *rightRotate(Node *y)
{
    Node *x = y->leftSon;
    Node *z = x->rightSon;

    // rotation

    x->rightSon = y;
    y->leftSon = z;

    // update height
    y->height = uptHeight(y);
    x->height = uptHeight(x);

    return x;
}

Node *leftRotate(Node *y)
{

    Node *x = y->rightSon;
    Node *z = x->leftSon;

    // rotation

    x->leftSon = y;
    y->rightSon = z;

    // update height
    y->height = uptHeight(y);
    x->height = uptHeight(x);

    return x;
}

Node *insert(Node *node, int key)
{
    // finding a place to insert the new node
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->leftSon = insert(node->leftSon, key);
    else if (key > node->key)
        node->rightSon = insert(node->rightSon, key);
    else
        return node;

    // update the height
    node->height = uptHeight(node);

    int balance = getBalance(node);

    // balancing and rotating

    if (balance > 1 && key < node->leftSon->key)
        return rightRotate(node);

    if (balance < -1 && key > node->rightSon->key)
        return leftRotate(node);

    if (balance > 1 && key > node->leftSon->key)
    {
        node->leftSon = leftRotate(node->leftSon);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->rightSon->key)
    {
        node->rightSon = rightRotate(node->rightSon);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->leftSon);
        printf("%d ", root->key);
        inOrder(root->rightSon);
    }
}

int main()
{
    Node *root = NULL;

    int values[] = {30, 20, 10, 25, 40, 22};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal of the final balanced AVL tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}