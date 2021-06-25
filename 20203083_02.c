/* AVL TREE - 20203083

1. Node Height
2. Left Node | Right Node 
3. LL, RR, LR, RL
4. Replace
5. Inser, Delete, Destory, Search

*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    int height;
    struct Node *right;
    struct Node *left;
};

int height(struct Node *N)
{
    if (N == NULL) {
	   return 0;	
	}
    return N->height;
}

int last(int a, int b);

int last(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key    = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct Node *rotate_R(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *set = x->right;
  
    x->right = y;
    y->left = set;

    y->height = last(height(y->left), height(y->right))+1;
    x->height = last(height(x->left), height(x->right))+1;
    
    return x;
}

struct Node *rotate_L(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *set = y->left;

    y->left = x;
    x->right = set;
  
    x->height = last(height(x->left), height(x->right)) +1;
    y->height = last(height(y->left), height(y->right)) +1;
  
    return y;
}

int get_Balance(struct Node *N)
{
    if (N == NULL) {
    	return 0;
	}
    return height(N->left) - height(N->right);
}
  
struct Node* inser(struct Node* node, int key)
{
    if (node == NULL) {
        return(newNode(key));
	}
    if (key < node->key) {
        node->left  = inser(node->left, key);
	}
    else if (key > node->key) {
    	node->right = inser(node->right, key);
	}
    else {
    	return node;
	}
  
    node->height = 1 + last(height(node->left), height(node->right));
  
    int balance = get_Balance(node);
  
    if (balance > 1 && key < node->left->key) {
       return rotate_R(node);
	}

    if (balance < -1 && key > node->right->key) {
    	return rotate_L(node);
	}

    if (balance > 1 && key > node->left->key)
    {
        node->left =  rotate_L(node->left);
        return rotate_R(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_R(node->right);
        return rotate_L(node);
    }
    
    return node;
}

struct Node * least_Node(struct Node* node)
{
    struct Node* cur = node;
  
    while (cur->left != NULL) {
    	cur = cur->left;
	}
  
    return cur;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL) {
    	return root;
	}
  
    if (key < root->key) {
    	root->left = deleteNode(root->left, key);
	}

    else if(key > root->key) {
    	root->right = deleteNode(root->right, key);
	}
  
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left : root->right;
            
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;

            free(temp);
        }
        else
        {
            struct Node* temp = least_Node(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }
  
    if (root == NULL) {
    	return root;
	}
	
    root->height = 1 + last(height(root->left),
                           height(root->right));
  
    int balance = get_Balance(root);
  
    if (balance > 1 && get_Balance(root->left) >= 0) {
    	return rotate_R(root);
	}

    if (balance > 1 && get_Balance(root->left) < 0)
    {
        root->left =  rotate_L(root->left);
        return rotate_R(root);
    }
  
    if (balance < -1 && get_Balance(root->right) <= 0) {
    	return rotate_L(root);
	}
  
    if (balance < -1 && get_Balance(root->right) > 0)
    {
        root->right = rotate_R(root->right);
        return rotate_L(root);
    }
    return root;
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
  struct Node *root = NULL;
  
	printf("Inser node to AVL Tree: \n");
	
	int a[9] = {9, 1, 0, -1, 5, 2, 6, 10, 11};
	
	int i;
	
	for(i=0; i<9; i++) {
		printf("%d \n", a[i]);
	}
	
	printf(" \n");
	printf(" \n");
	
    root = inser(root, 9);
    root = inser(root, 5);
    root = inser(root, 10);
    root = inser(root, 0);
    root = inser(root, 6);
    root = inser(root, 11);
    root = inser(root, -1);
    root = inser(root, 1);
    root = inser(root, 2);
/*
          9
        /  \
       1    10
     /  \     \
    0    5     11
   /    /  \
  -1   2    6
*/
    printf("Preorder traversal of the constructed AVL tree is \n");
    preorder(root);
  
    root = deleteNode(root, 10);
/*
         1
       /  \
      0    9
    /     /  \
  -1    5     11
      /  \
     2    6
*/
    printf("\nPreorder traversal after deletion of 10 \n");
    preorder(root);
  
    return 0;
}
