#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class bstNode
{
private:
    int data;
    bstNode* left;
    bstNode* right;
public:

    int element()
    {
        return data;
    }
    void setElement(int x)
    {
        data=x;
    }
    void setLeft(bstNode* lft)
    {
        left=lft;
    }
    void setRight(bstNode* rght)
    {
        right=rght;
    }
    bstNode* getLeft()
    {
        return left;
    }
    bstNode* getRight()
    {
        return right;
    }
};
class bst
{
    //member variables
    bstNode* root;
    //helper functions
    bstNode* findmin(bstNode*);
    bstNode* insertHelp(bstNode*,int);
    bstNode* deleteHelp(bstNode*,int);
    bool findHelp(bstNode*,int);
    void InorderTraversalHelp(bstNode* );
    void PreorderTraversalHelp(bstNode* );
    void PostOrderTraversalHelp(bstNode* );
    bstNode* find_node_location(bstNode*,int);
    bstNode* deleteMin(bstNode*);
    void printHelp(bstNode*);
    bool isLeaf(bstNode* );
    void sblstHelp(bstNode*);
    void sbsqnceHelp(bstNode*);
public:
    bst()
    {
        root=(bstNode*)malloc(sizeof(bstNode));
        root=NULL;
    }
    void Insert(int);
    void Delete(int);
    bool Find(int);
    void InorderTraversal();
    void PreorderTraversal();
    void PostOrderTraversal();
    void print();
    bool sbsqnce(queue<int> );
    bool sblst(queue<int> );
};

bstNode* bst::insertHelp(bstNode* rt,int x)
{
    if(rt==NULL)
    {
        //root->data=x;
        bstNode* temp=(bstNode* )malloc(sizeof(bstNode));
        temp->setElement(x);
        temp->setLeft(NULL);
        temp->setRight(NULL);
        return temp;
    }
    //else
    if(x < rt->element())
        rt->setLeft(insertHelp(rt->getLeft(),x));
    else rt->setRight(insertHelp(rt->getRight(),x));//which is equivalent to rt->right=insertHelp(rt->right,x);
    return rt;
}
void bst::Insert(int x)
{
    root=insertHelp(root,x);
}
bstNode* bst::deleteHelp(bstNode* rt,int x)
{
    //if we are deleting the root
    if(rt==NULL)
        return NULL;
    //If not found or empty tree
    else if(x<(rt->element()))
    {
        rt->setLeft(deleteHelp(rt->getLeft(),x));
    }
    else if(x>(rt->element()))
    {
        rt->setRight(deleteHelp(rt->getRight(),x));
    }
    else{
        //let's go to that node
        //now 3 cases
        //case 1:the node is a leaf node,easiest approach
        if(rt->getLeft()==NULL && rt->getRight()==NULL)
        {
            free(rt);
            rt=NULL;
            return rt;
        }
        //case 2 : the node has only one child (left here)
        else if(rt->getRight()==NULL)
        {
            bstNode* temp=rt;
            rt=rt->getLeft();//i.e. rt=rt->left;
            free(temp);
            temp=NULL;
        }
        else if(rt->getLeft()==NULL)
        {
            bstNode* temp=rt;
            rt=rt->getRight();
            free(temp);
            temp=NULL;
        }
        else //if(rt->getLeft()!=NULL && rt->getRight()!=NULL)
        {
            bstNode* minOfRST=findmin(rt->getRight());
            rt->setElement(minOfRST->element());//rt->data=minOfRST->data;
//            cout<<"the element : "<<rt->element()<<endl;
            //now delete that duplicate node minOfRST
            rt->setRight(deleteMin(rt->getRight()));
    //        bstNode* temp=minOfRST;
    //        temp=temp->getLeft();//there exists no RST ,if there would exist one,the max value would be there and NOT here
    //        delete
            free(minOfRST);
        }
    }
    return rt;
}

void bst::Delete(int x)
{
    bool flag=Find(x);
    if(flag==false)
    {
        //cout<<"item not found!!Can't delete\n";//---------------------------------------------------------------------------------------------------
        return ;
    }
    root=deleteHelp(root,x);
}

bstNode* bst::findmin(bstNode* rt)
{
    if(rt->getLeft()==NULL)
    {
        return rt;
    }
    //else
    else return findmin(rt->getLeft());
}
void bst::InorderTraversalHelp(bstNode* rt)
{
    if(rt==NULL)
    {
        return;
    }
    InorderTraversalHelp(rt->getLeft());
    cout<<rt->element()<<" ";
    InorderTraversalHelp(rt->getRight());
//    cout<<"\n";
}
void bst::InorderTraversal()
{
    InorderTraversalHelp(root);
    cout<<"\n";
}
void bst::PreorderTraversalHelp(bstNode* rt)
{
    if(rt==NULL)
    {
        return;
    }
    cout<<rt->element()<<" ";
    PreorderTraversalHelp(rt->getLeft());
    PreorderTraversalHelp(rt->getRight());
//    cout<<"\n";
}
void bst::PreorderTraversal()
{
    PreorderTraversalHelp(root);
    cout<<"\n";
}
void bst::PostOrderTraversalHelp(bstNode* rt)
{
    if(rt==NULL)
    {
        return;
    }
    PostOrderTraversalHelp(rt->getLeft());
    PostOrderTraversalHelp(rt->getRight());
    cout<<rt->element()<<" ";
}
void bst::PostOrderTraversal()
{
    PostOrderTraversalHelp(root);
    cout<<"\n";
}
bool bst::findHelp(bstNode* rt,int x)
{
    if(rt==NULL)
    {
        return false;
    }
    else if(x<(rt->element()))
        return findHelp(rt->getLeft(),x);
    else if(x > (rt->element()))
        return findHelp(rt->getRight(),x);
    else return true;
}
bool bst::Find(int x)
{
    return findHelp(root,x);
}
bstNode* bst::find_node_location(bstNode* rtptr,int x)
{
    if(rtptr==NULL)
        return NULL;
    else if(x<rtptr->element())
        find_node_location(rtptr->getLeft(),x);
    else if(x>rtptr->element())
        find_node_location(rtptr->getRight(),x);
    else{
        //found
        return rtptr;
    }
}
bstNode* bst::deleteMin(bstNode* rt)
{
    if(rt->getLeft()==NULL)
    {
        //WE HAVE GOT OUR MAX VALUED NODE IN THE LST
//        bstNode* temp=rt;
//        bstNode* temproot=root->getLeft();
//        free(temp);
//        return temproot;
          return rt->getRight();
    }
    else{
        rt->setLeft(deleteMin(rt->getLeft()));
        return rt;
    }
}
void bst::print()
{
    cout<<"(";
    printHelp(root);
    cout<<")\n";
}
void bst::printHelp(bstNode* rt)
{
    if(rt==NULL)
    {
        return;
    }
    cout<<rt->element();
    if(rt->getLeft() || rt->getRight())
        {
            cout<<"(";
            if(rt->getLeft())
                printHelp(rt->getLeft());
            cout<<",";
            if(rt->getRight())
                printHelp(rt->getRight());
//    if(isLeaf(rt)==false)
            cout<<")";
        }
}
bool bst::isLeaf(bstNode* node)
{
    if(node->getLeft()==NULL && node->getRight()==NULL)
        return true;
    //else
    return false;
}
queue<int> q;
bool startFound,flag,isRunning;
bool bst::sbsqnce(queue<int> qp)
{
    startFound=false;
    flag=true;
    while(q.empty()==false)
    {
        startFound=Find(q.front());
        if(startFound==false)
            flag=false;
        q.pop();
    }
    //sbsqnceHelp(root);
    return flag;
}
void bst::sblstHelp(bstNode* rt)
{
    if(rt==NULL)
        return ;
    sblstHelp(rt->getLeft());
    if(rt->element()==q.front() && q.empty()==false && startFound==false)
    {
       // cout<<"q.front()1c "<<q.front()<<"\n";
        startFound=true;//initially it was false
        q.pop();
    }
    else if(startFound==true && q.empty()==false && isRunning==true)
    {
       // cout<<"q.front()2c "<<q.front()<<"\n";
        if(rt->element()== q.front())
        {
            isRunning=true;//overwriting
            q.pop();
        }
        else isRunning=false;
    }
    sblstHelp(rt->getRight());
}
bool bst::sblst(queue<int> qp)
{
    while(q.empty()==false)
    {
        q.pop();
    }
    q=qp;
    startFound=false;
    isRunning=true;
    sblstHelp(root);
    return (startFound && isRunning);
}
#endif // BST_H_INCLUDED
