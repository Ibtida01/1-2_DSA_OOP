#include<iostream>
#include<fstream>
#include "heap.h"

using namespace std;
int n1,n2,x;
Heap<int> join(Heap<int> p1,Heap<int> p2)
{
    Heap<int> merged(n1+n2);
    int x;
    while(p1.isEmpty()==false)
    {
        x=p1.ExtractMax();
        merged.Insert(x);
    }
    while(p2.isEmpty()==false)
    {
        x=p2.ExtractMax();
        merged.Insert(x);
    }
    return merged;
}
int main()
{
//    freopen("in2.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin>>n1>>n2;
    Heap<int> p1(n1),p2(n2);
    for(int i=0;i<n1;i++)
    {
        cin>>x;
        p1.Insert(x);
    }
    for(int i=0;i<n2;i++)
    {
        cin>>x;
        p2.Insert(x);
    }
    Heap<int> mpq=join(p1,p2);
    mpq.Print();
//    Heap<int> h(20);
//    int q,p;
//    while(1)
//    {
////        cout<<
//        cin>>q;
//        if(q==1)
//        {
//            cin>>p;
//            h.Insert(p);
//        }
//        else if(q==2)
//        {
//            cout<<"Max: "<<h.FindMax()<<endl;
//        }
//        else if(q==3)
//        {
//            h.ExtractMax();
//        }
//        else if(q==4)
//        {
//            int idx;
//            cin>>idx>>p;
//            h.IncreaseKey(idx,p);
//        }
//        else if(q==5)
//        {
//            int idx;
//            cin>>idx>>p;
//            h.DecreaseKey(idx,p);
//        }
//        else if(q==6)
//        {
//            h.Print();
//        }
//        else if(q==7)
//        {
//            h.Sort();
//            exit(0);
//        }
//        else
//        {
//            cout<<"Invalid input!\n";
//        }
//    }
}
