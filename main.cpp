#include"autoSuggest.h"
#include"dictionary.h"
int main()
{
    struct TrieNode* root = getNode();
    string word;
    fstream file;
    string filename="code.txt";
    file.open("code.txt");
    string s="";
    while(file){

        string p;
        getline(file,p);
        insert(root, p);
    }

    cout<<"Enter the word:-"<<endl;
    cin>>word;
    int comp = printAutoSuggestions(root,word );

    if (comp == -1)
        cout << "No other strings found with this prefix\n";

    else if (comp == 0)
        cout << "No string found with this prefix\n";
    for(int i=0;i<suggest.size();i++)
        cout<<i+1<<":- "<<suggest[i]<<endl;
    cout<<"Enter word index to get meaning:-> ";
    int g;
    cin>>g;
    intro();
    prog(suggest[g-1]);


    return 0;
}
