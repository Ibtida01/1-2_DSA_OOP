#ifndef LISTARR_H
#define LISTARR_H
#include<iostream>
#include<stdlib.h>

using namespace std;
template <typename t>
class lst
{
    int currentsz=0;
    t* listarr;
    int sz;
    int frontidx,backidx;
    void print()
    {
        int ct=0;
        cout<<"< ";
        for(int i=frontidx; ct<currentsz; ct++)
        {
            cout<<listarr[i]<<" ";
            i=(++i)%sz;
        }
        cout<<">\n";

    }
public:

    lst()
    {
        listarr=(t* )malloc(sizeof(t)*5);
        sz=5;
        currentsz=0;
        frontidx=backidx=0;
    }
    void enqueue(t item)
    {
        ++currentsz;
        if(currentsz>sz)
        {
            t* temp=(t* )malloc(sizeof(t)*sz);
            for(int i=0; i<sz; i++)
            {
                temp[i]=listarr[i];
            }
            listarr=(t* )malloc(sizeof(t)*2*sz);
            for(int i=frontidx,j=0; j<sz; )
            {
                listarr[j++]=temp[i];
                i=(++i)%sz;
            }
            sz=2*sz;
            free(temp);
            frontidx=0;
            backidx=currentsz-1;
        }
        listarr[backidx]=item;
        backidx=(++backidx)%sz;
        print();
    }
    t dequeue()
    {
        if(currentsz==0)
        {
            cout<<"Error!!Queue is empty!!\n";
            return -1;
        }
        t retVal=listarr[frontidx];
        frontidx=(frontidx+1)%sz;
        --currentsz;
        print();
        return retVal;
    }
    int length()
    {
        print();
        return currentsz;
    }
    t front()
    {
        if(currentsz==0)
        {
            cout<<"Error!!Queue is empty!!\n";
            print();
            return -1;
        }
        print();
        return listarr[frontidx];
    }
    t back()
    {
        if(currentsz==0)
        {
            cout<<"Error!!Queue is empty!!\n";
            print();
            return -1;
        }
        print();
        return listarr[backidx-1];
    }
    bool is_empty()
    {
        print();
        if(currentsz==0)
            return true;
        return false;
    }
    void clear()
    {
        currentsz=0;
        frontidx=0;
        backidx=0;
        print();
    }
};

#endif // LISTARR_H

/*
1 12
1 13
1 14
1 15
1 16
2
1 17
1 18
1 19
1 20
1 21
1 22
2
1 23
1 24
3
4
5
*/
