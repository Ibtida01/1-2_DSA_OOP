#include<iostream>
#include<fstream>
#include "heap.h"

using namespace std;
int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Heap<int> h(20);
    int q,p;
    while(1)
    {
//        cout<<
        cin>>q;
        if(q==1)
        {
            cin>>p;
            h.Insert(p);
        }
        else if(q==2)
        {
            cout<<"Max: "<<h.FindMax()<<endl;
        }
        else if(q==3)
        {
            h.ExtractMax();
        }
        else if(q==4)
        {
            int idx;
            cin>>idx>>p;
            h.IncreaseKey(idx,p);
        }
        else if(q==5)
        {
            int idx;
            cin>>idx>>p;
            h.DecreaseKey(idx,p);
        }
        else if(q==6)
        {
            h.Print();
        }
        else if(q==7)
        {
            h.Sort();
            exit(0);
        }
        else
        {
            cout<<"Invalid input!\n";
        }
    }
}
