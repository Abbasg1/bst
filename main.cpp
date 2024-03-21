#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
/*
ghazi a
binary search tree implementation
spring sem shs data structures, galbraith

***"numbers.txt"***

sources:
https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
https://www.youtube.com/watch?v=pYT9F8_LFTM
https://www.youtube.com/watch?v=mtvbVLK5xDQ
+ hash tables project from my repository
+
*/

//node class
class Node
{
public: 
    int data;
    Node* right;
    Node* left;
    Node(int d, Node* r, Node* l) 
    {
        this->data= d;
        this->right = r;
        this->left = l;
    }
    //default constructor/destructor
    Node() 
    {
        data = 0;
        right = NULL;
        left = NULL;
    }
    ~Node(){}
};

//function protoypes
Node* remove(Node* curr, int n);
void insert(Node*& curr, int num);
void print(Node* curr, int h);
void search(Node* curr, int n);
void mInput();
void fInput();


Node* root= NULL;;


//driver
int main()
{
    char str[30];
    //bool run = false; //controls do while
    cout << "Enter F to use auto generation, M for manual" << endl;
    
    char rsp[5];
    
    cin>>rsp;
    if(strcmp(rsp, "F")== 0 || strcmp(rsp, "f")== 0)
    {
        fInput();
        //run = true;
    }
    else if(strcmp(rsp,"M")== 0 || strcmp(rsp,"m")== 0)
    {
        mInput();
        //run = true;
    }
    else
    {
        cout << "invalid/bad code"<< endl;
    }


    print(root, 0);
    char cmd[5];
    //hjas to be outside, used for every cmd
    int number = 0;
    while(true)
    {
        cout << "A for add, R for remove, P for print,S for search, Q to quit. "<< endl;
        cin >> cmd;
    
        if(strcmp(cmd, "A") == 0|| strcmp(cmd, "a")== 0)
        {
            cout << "enter the number"<< endl;
            cin >> number;
            insert(root, number);
            cout << "added" << endl;
        }else if(strcmp(cmd, "S")== 0 || strcmp(cmd, "s")== 0)
        {
            cout << "Enter the number youre searching for ";
            cin >> number;
            search(root, number);
        }else if(strcmp(cmd, "R")== 0 || strcmp(cmd, "r")== 0)
        {
            cout << "Enter the number youre removing";
            cin >> number;
            cin.get();
            root = remove(root, number);

        }else if(strcmp(cmd, "P")== 0 || strcmp(cmd, "p")== 0)
        {
            print(root,0);
        }else if(strcmp(cmd, "Q") != 0|| strcmp(cmd, "q") != 0)
        {
            break;
        }
        else
        {
            cout << "invalid " << endl;
        }
    }
    
}
//fxns without class
Node* remove(Node* curr, int n)
{//recursive searching, determining children and base cases
  if (curr == NULL) 
  {
    return curr;
  }
  if (n > curr->data) 
  {
    curr->right = remove(curr->right, n);
    return curr;
  }
  if (n < curr->data) 
  {
    curr->left = remove(curr->left, n);
    return curr;
  }
  else 
  {
    //how many child nodes
    if (curr->right == NULL && curr->left == NULL) 
    {
      return NULL;
    }
    else if (curr->left == NULL) 
    {
      Node * temp = curr->right;
      delete curr;
      return temp;
    }
    else if (curr->right == NULL) 
    {
      Node * temp = curr->left;
      delete curr;
      return temp;
    }
    else 
    {
      Node * sParent = curr;
      Node * s = curr->left;
      //replacement
      while (s->right != NULL) 
      {
	    sParent = s;
	    s= s->right;
      }
      if (sParent !=curr) 
      {
	    sParent->right = s->left;
      }
      //left node
      else 
      {
	    sParent->left = s->left;
      }
      curr->data = s->data;
      delete s;
      return curr;
    }
  }

  return curr;
}
void insert(Node*& curr, int num)
{
    if (curr == NULL) 
    {
        curr = new Node(num, NULL, NULL);
        return;
    }
    if (num >= curr->data) 
    {
        if (curr->right == NULL) 
        {
            curr->right = new Node(num, NULL, NULL);
            return;
        }
        else 
        {
            insert(curr->right, num);
        }
    }else 
    {
        if (curr->left == NULL) 
        {
            curr->left = new Node(num, NULL, NULL);
            return;
        }
        else 
        {
            insert(curr->left, num);
        }
    }


}
void print(Node* curr, int h)
{
  if (curr== NULL) 
  {
    return;
  }

  print(curr->right, h + 1);

  for (int i = 0; i < h; i++) 
  {
    cout << "\t";
  }
  cout << curr->data << endl;
  print(curr->left, h + 1);
}
void search(Node* curr, int n)
{
int data = 0;
  
  while (curr != NULL) 
  {
    data = curr->data;
    if (data == n) 
    {
      cout << "Found in tree" << endl;
      return;
    }
    if (n > data) 
    {
      curr = curr->right;
    }
    else 
    {
      curr = curr->left;
    }
  }

  cout << "Couldnt be found in tree" << endl;
}
void mInput()
{
  int numIn = 0;
  int numCount = 0;
  cout << "enter up to 30 numbers, or enter -1 to break" << endl;
  while (numIn != 0 || numCount < 30) 
  {
    cout << endl;
    cout << "Enter a number: ";
    cin >> numIn;
    if (numIn == -1) 
    {
      break;
    }
    else 
    {
        insert(root, numIn);
        cout << "Number entered" << endl;
        numCount++;
    }
  }
}

//from hashtables mostly
void fInput()
{
    ifstream numbers("numbers.txt");
    srand(time(NULL));
    int num = 0;
    vector<int> nums;

    while (numbers >> num) 
    {
        nums.push_back(num);
    }

    int count = 0;
    cout << "File found, numbers: " << endl;
    while (count != 10 && !nums.empty()) // Ensure nums vector is not empty
    {
        int randomIndex = rand() % nums.size(); // Generate random index within bounds
        num = nums.at(randomIndex);
        cout << num << " ";
        insert(root, num);
        nums.erase(nums.begin() + randomIndex); // Remove used number from vector
        count++;
    }
    cout << endl;
}