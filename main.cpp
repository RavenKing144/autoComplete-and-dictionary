#include"dictionary.h"

  int main()
{
  Node *root = NULL;
  dictionary *d;
  fstream file;
  file.open("file.txt");
  while(!file.eof())
  {
    string word="",meaning="",temp="";
    getline(file,temp);
    int pos=temp.find(":");
    word=temp.substr(0,pos);
    meaning=temp.substr(pos+1);
    //cout<<word<<" "<<meaning<<endl;
    root=d->insert(root,word,meaning);
  }
  d->preOrder(root);
  Node* s=d->search(root,"help");
  if(s)
    cout<<s->meaning<<endl;
  else
    cout<<"word not found"<<endl;
  return 0;
}
