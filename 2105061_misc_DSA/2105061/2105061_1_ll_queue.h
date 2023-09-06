#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<stdlib.h>

using namespace std;
class node
{
    int data;
    node* nxt;
    node* head;
    node* tail;
    int currsz;
    void traverseQ();
public:

    // void init(int);
    node()
    {
        head=(node*)malloc(sizeof(node));
        tail=(node*)malloc(sizeof(node));
        head->data=-1;
        head->nxt=NULL;
        //creating tail
        node* tail=head;
        currsz=0;
    }
    void enqueue(int item);
    int dequeue();
    int length();
    int front();
    int back();
    bool is_empty();
    void clear();
};

#endif // NODE_H
