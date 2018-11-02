
struct Node
{
    string word;
    string mean;
    Node *left;
    Node *right;
    int height;
};


int max(int a, int b);


int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}


struct Node* newNode(string word, string mean)
{
    Node* node = new Node;
    node->word = word;
    node->mean = mean;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    
    return y;
}


int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Node* insert(Node* node, string word, string mean )
{
    
    if (node == NULL)
        return(newNode(word,mean));

    if (word < node->word)
        node->left  = insert(node->left, word,mean);
    else if (word > node->word)
        node->right = insert(node->right, word,mean);
    else 
        return node;

    
    node->height = 1 + max(height(node->left),
                           height(node->right));

    
    int balance = getBalance(node);

   
    if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    
    if (balance > 1 && word > node->left->word)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    
    if (balance < -1 && word < node->right->word)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    
    return node;
}


Node* search(Node* root, string word)
{
   
    if (root == NULL || root->word == word)
       return root;

    
    if (root->word < word)
       return search(root->right, word);

    
    return search(root->left, word);
}


