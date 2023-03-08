#include<iostream>
#include<conio.h>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

struct node
{
    int val;
    node* link;
};

class stack
{
private:
    int stacksize;
    node* head;
    
public:
    stack()
    {
        stacksize=0;
        head = NULL;
    }
    void push(int g)
    {
        node* temp=new node();
        temp->val = g;
        temp->link = head;
        head = temp;
        cout<<"\npushed : "<<g<<endl;
        stacksize ++;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout<<"\nEmpty stack can not pop"<<endl;
            return -1;
        }    
        node* temp = head;
        head = temp->link;
        temp->link = NULL;
        cout<<"\nPopped : "<<temp->val<<endl;
        delete[] temp;
        stacksize --;
    }
    int top()
    {
        if (head == NULL)
        {
            cout<<"\nEmpty stack no top value "<<endl;
            return -1;
        }
        cout<<"\nTop value : "<<head->val<<endl;
        return head->val;
    }
    int stsize()
    {
        if (head == NULL)
        {
            cout<<"\nStack is empty can not calculate size "<<endl;
            return -1;
        }
        cout<<"\nStack size : "<<stacksize;
        return stacksize;        
    }
};

int main()
{
    stack s;
    int psize,popsize, x;
    cout<<"how many nodes to create : ";
    cin>>psize;
    int *arr = new int(psize);
    for (int i = 0; i < psize; i++)
    {
        cout<<"\nEnter value ";
        cin>>x;
        s.push(x);
    }
    cout<<"\nHow many numbers to pop : ";
    cin>>popsize;
    for (int i = 0; i < popsize; i++)
    {
        s.pop();
    }
    
    s.top();    
    s.stsize();
    
    
    return 0;
}