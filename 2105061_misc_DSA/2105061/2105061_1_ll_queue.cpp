#include<iostream>
#include"2105061_1_ll_queue.h"
using namespace std;

void node::enqueue (int item)
{
    node* temp=(node* )malloc(sizeof(node));
    temp->data=item;
    temp->nxt=NULL;
    if(currsz==0)
        head->nxt=temp;
    tail->nxt=temp;
    ++currsz;
    tail=temp;
    traverseQ();
}

void node::traverseQ()
{
    node* hd=head->nxt;
    cout<<"< ";
    while(hd!=NULL)
    {
        cout<<hd->data<<" ";
        hd=hd->nxt;
    }
    cout<<">\n";
}

void node::clear()
{
    if(currsz==0)
    {
        cout<<"queue is empty,nothing to clear\n";
        traverseQ();
        return ;
    }
    node* hd=head->nxt;
    node* temp;
    while(hd!=NULL)
    {
        temp=hd;
        hd=hd->nxt;
        delete temp;
    }
    head->nxt=NULL;
    tail=head;
    currsz=0;
    traverseQ();
}

int node::length()
{
    traverseQ();
    return currsz;
}

int node::dequeue()
{
    if(currsz<=0)
    {
        cout<<"Error!Queue is empty!!\n";
        traverseQ();
        return -1;
    }
    int retVal;
    node* tempPtr=head->nxt;
    retVal=tempPtr->data;
    head->nxt=tempPtr->nxt;
    delete tempPtr;
    --currsz;
    traverseQ();
    return retVal;
}

int node::front()
{
    if(currsz>0)
        return (head->nxt)->data;
    else {
            cout<<"Error!Queue is empty!!\n";
            return -1;
    }
}

int node::back()
{
    if(currsz>0)
        return (tail->data);
    else {
            cout<<"Error!Queue is empty!!\n";
            return -1;
         }
}

bool node::is_empty()
{
    if(currsz>0)
        return false;
    return true;
}




