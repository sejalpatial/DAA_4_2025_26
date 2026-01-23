/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node *left,*right;
    
    Node(char c,int f)
    {
        ch=c;
        freq=f;
        left=right=NULL;
    }
};
struct compare{
    bool operator()(Node *l,Node *r){
        return l->freq>r->freq;
    }
};
void generate(Node* root,string code,unordered_map<char,string>& huffmanCode) {
    if (!root)
        return;

    if(!root->left && !root->right)
    {
        huffmanCode[root->ch]=code;
    }
    generate(root->left,code+"0",huffmanCode);
    generate(root->right,code+"1",huffmanCode);
}

int main()
{
    string str;
    cout<<"enter the string";
    getline(cin,str);
    unordered_map<char,int>freq;
    for(char ch:str)
    {
        freq[ch]++;
    }
    priority_queue<Node*,vector<Node*>,compare>pq;
    for(auto pair:freq)
    {
        pq.push(new Node(pair.first,pair.second));
    }
    while(pq.size()>1)
    {
        Node *left=pq.top();pq.pop();
        Node *right=pq.top();pq.pop();
        
        Node *parent=new Node('\0',left->freq+right->freq);
        parent->left=left;
        parent->right=right;
        pq.push(parent);
        
    }
    Node *root=pq.top();
    unordered_map<char,string>huffmanCode;
    generate(root, "", huffmanCode);
    string encodedStr = "";
    for (char ch : str) {
        encodedStr += huffmanCode[ch];
    }
    cout<<"Original"<<str<<endl;
    cout<<"Encoded"<<encodedStr<<endl;
    return 0;
}




    
    
    

