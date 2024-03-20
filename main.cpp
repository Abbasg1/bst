#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
/*
ghazi a
binary search tree implementation
spring sem shs data structures, galbraith

sources;


*/

//node class
class Node
{
public: 
    int data;
    Node* right;
    Node* left;
    Node(int d, Node* r, Node* l);
    //default constructor/destructor
    Node();
    ~Node();


};

Node::Node(int d, Node* r, Node* l) 
{
  this->data= d;
  this->right = r;
  this->left = l;
}

Node::Node() 
{
  data = 0;
  right = NULL;
  left = NULL;
}

Node::~Node() {}

//function protoypes
Node* remove(Node* curr, int n);
void insert(Node*& curr, int num);
void print(Node* curr, int l);
void search(Node* curr, int n);
void mInput();
void fInput();


Node* root= NULL;;


//driver
int main()
{
    char str[30];
    bool run = false; //controls do while
    do 
    {
        cout << "Enter F to use auto generation, M for manual" << endl;
        
        char rsp[5];
        
        cin>>rsp;
        if(strcmp(rsp, "F") || strcmp(rsp, "f"))
        {
            fInput();
            run = true;
        }
        else if(strcmp(rsp,"M") || strcmp(rsp,"m"))
        {
            mInput();
        }
        else
        {
            cout << "invalid/bad code"<< endl;
            run = true;
        }
    } 
    while(run==false);

    print(root, 0);
    char cmd[5];
    //hjas to be outside, used for every cmd
    int number = 0;
    cout << "A for add, R for remove, P for print,S for search, Q to quit. "<< endl;
    cin >> cmd;

    if(strcmp(cmd, "A") || strcmp(cmd, "a"))
    {
        cout << "enter the number"<< endl;
        cin >> number;
        insert(root, number);
        cout << "added" << endl;
    }else if(strcmp(cmd, "S") || strcmp(cmd, "s"))
    {
        cout << "Enter the number youre searching for ";
        cin >> number;
        search(root, number);
    }else if(strcmp(cmd, "R") || strcmp(cmd, "r"))
    {
        cout << "Enter the number youre removing";
        cin >> number;
        cin.get();
        root = remove(root, number);

    }else if(strcmp(cmd, "Q") || strcmp(cmd, "q"))
    {
        return;
    }else if(strcmp(cmd, "P") || strcmp(cmd, "p"))
    {
        print(root,0);
    }else 
    {
        cout << "invalid " << endl;
    }





}