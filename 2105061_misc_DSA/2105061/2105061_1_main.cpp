#include<iostream>
#include"2105061_1_a_queue.h"
using namespace std;

int main()
{
    lst<int> qu;
    int Q,P;
    while(1)
    {
        cin>>Q;
        if(Q==0)
            break;
        else if(Q==1)
        {
            cin>>P;
            qu.enqueue(P);
        }
        else if(Q==2)
        {
           cout<<qu.dequeue()<<endl;
        }
        else if(Q==3)
        {
           cout<<qu.length()<<"\n";
        }
        else if(Q==4)
        {
           cout<<qu.front()<<endl;
        }
        else if(Q==5)
        {
            cout<<qu.back()<<endl;
        }
        else if(Q==6)
        {
            if(qu.is_empty()==true)
                cout<<"true\n";
            else cout<<"false\n";
        }
        else if(Q==7)
        {
            qu.clear();
        }
        else
        {
            cout<<"INVALID SELECTION\n";
        }

    }


}
