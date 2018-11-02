
struct avl_node
{
  string word;
  string meaning;
  avl_node * right;
  avl_node * left;
  int height;
};
int max(int a, int b);

int height(avl_node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a,int b)
{
    return (a > b)? a : b;
}

avl_node * newNode(string word,string meaning)
{
  avl_node * node= new avl_node;
  node->word=word;
  node->meaning=meaning;
  node->left=NULL;
  node->right=NULL;
  node->height=1;
  return node;
}

avl_node * rightRotate(avl_node * y)
{
  avl_node * x=y->left;
  avl_node * temp=x->right;
  x->right=y;
  y->left=temp;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return x;
}

avl_node * leftRotate(avl_node * x)
{
  avl_node * y=x->right;
  avl_node * temp=y->left;
  y->left=x;
  x->right=temp;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return y;
}

int Balance(avl_node * n)
{
  if(n==NULL)
    return 0;
  return height(n->left)-height(n->right);
}

avl_node * insert(avl_node * node,string word,string meaning)
{
  if(node==NULL)
    return(newNode(word,meaning));;

  if(word<node->word)
    node->left=insert(node->left,word,meaning);
  else if(word>node->word)
    node->right=insert(node->right,word,meaning);
  else
    return node;
  node->height=1+max(height(node->left), height(node->right));
  int balance =Balance(node);

  if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    if (balance > 1 && word> node->left->word)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && word< node->right->word)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

return node;

}
 avl_node * search(avl_node * root,string word)
 {
  if(root!=NULL)
  {
    if(root->word==word)
      return root;
    if(root->word<word)
      return search(root->right,word);
    if(root->word>word)
      return search(root->left,word);
  }
  cout<<"not found"<<endl;
  }

