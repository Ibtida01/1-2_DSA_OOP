#include "BST.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    bst b1;
//    b1.Insert(5);
//    b1.Insert(10);
//    b1.Insert(3);
//    b1.InorderTraversal();
//    cout<<"\n";
//    b1.Insert(33);
//    b1.Delete(5);
//    b1.InorderTraversal();
//    cout<<"\n";
//    b1.Insert(1);
//    b1.Insert(7);
//    b1.print();
//    cout<<"\n";
//    b1.Delete(10);
//    b1.InorderTraversal();
//    cout<<"\n";

/////main
 char q;
 int p;
 while(cin>>q)
 {
     if(q=='I')
        {
            cin>>p;
            b1.Insert(p);
            b1.print();
        }
    else if(q=='D')
    {
        cin>>p;
        b1.Delete(p);
        b1.print();
    }
    else if(q=='F')
    {
        cin>>p;
        if(b1.Find(p)==true)
            cout<<"found\n";
        else cout<<"not found\n";
    }
    else if(q=='T')
    {
        string cmd;
        cin>>cmd;
        if(cmd=="In")
        {
            b1.InorderTraversal();
        }
        else if(cmd=="Pre")
        {
            b1.PreorderTraversal();
        }
        else{
            if(cmd=="Post")
                b1.PostOrderTraversal();
        }
    }
    else if(q== 'C')
    {
        cin>>p;
        queue <int> qu,quCopy;
        int x;
        for(int i=0;i<p;i++)
        {
          cin>>x;
          qu.push(x);
        }
        //QUEUE IS WORKING PROPERLY,CHECKED
        bool hasSublist=b1.sblst(qu);
        bool hasSubsequence=b1.sbsqnce(qu);
        if(hasSublist==false && hasSubsequence==false)
            cout<<"none\n";
        else if(hasSublist==true)
            cout<<"sublist\n";
        else if(hasSublist==false && hasSubsequence==true)
            cout<<"subsequence\n";
    }
 }
}

