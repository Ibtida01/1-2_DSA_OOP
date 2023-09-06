#include "2105061_2_stack.h"

using namespace std;

int main()
{
    stack <int> s;
    int q,p;
    while(1)
    {
        cin>>q;
        if(q==0)
        {
            exit(0);
        }
        else if(q==1)
        {
            s.clear();
        }
        else if(q==2)
        {
            cin>>p;
            s.push(p);
        }
        else if(q==3)
        {
            cout<<s.pop()<<endl;
        }
        else if(q==4)
        {
            cout<<s.length()<<endl;
        }
        else if(q==5)
        {
            cout<<s.topValue()<<endl;
        }
        else if(q==6)
        {
            if(s.isEmpty()==true)
                cout<<"True\n";
            else cout<<"False\n";
        }
        else{
            cout<<"INVALID SELECTION\n";
        }
    }
}
