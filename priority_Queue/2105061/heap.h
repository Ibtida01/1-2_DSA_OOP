#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include<iostream>
#include<cmath>
using namespace std;
template<typename t>
class Heap
{
private:
    t* arr;
    int currsz;
    int SIZE;
    int parent(int idx)
    {
        return (idx/2);//same as taking floor
    }
    void maxHeapify(int i)
    {
        int l,r;
        l=2*i;//l is the left child of i
        r=2*i+1;//right child of i
        t largest;//it might seem that we can initiate largest with i, i.e largest=i
        //but what if the leftchild simply DNE?i.e l > currsz ??so we need the following code block
        if(l <= currsz && arr[i] < arr[l])
            largest=l;
        else largest=i;
        if(r <= currsz && arr[l] < arr[r])//if right child exists AND right child has higher value
            largest=r;
        if(i!=largest) // if a[i] is not the largest among its children ...
        {
            std::swap(arr[i], arr[largest]);
            i=largest;
            maxHeapify(i);
        }
    }
    void heapifyUp(int i)
    {
        t p=parent(i);//p=parent if index i
        while(i>=1 && arr[p]<arr[i])
        {
            std::swap(arr[i],arr[p]);
            i=p;
            p=parent(i);
        }
    }

    t ExtractMaxSilent()
    {
        if(currsz==0)
        {
           return -1;
        }
        //else
        t retVal=arr[1];
        arr[1]=arr[currsz];
        --currsz;
        maxHeapify(1);
        return retVal;
    }

public:
    Heap(int sz)
    {
        arr=new t[sz+1];
        currsz=0;
        SIZE=sz;
    }
    void Insert(t x)
    {
        if(currsz==SIZE)
        {
            t* temp=new int[SIZE+1];
            for(int i=1;i<=currsz;i++)
            {
                temp[i]=arr[i];
            }
            arr=new t[2*SIZE+1];
            for(int i=1;i<=currsz;i++)
            {
                arr[i]=temp[i];
            }
        }
        //now we can insert
        arr[++currsz]=x;
        //heapify UP
       heapifyUp(currsz);
    }
    t FindMax()
    {
        if(currsz>0)
            return arr[1];
        else
        {
            cout<<"Heap is empty!\n";
            return -1;
        }
    }
    t ExtractMax()
    {
        if(currsz==0)
        {
            cout<<"Heap is empty!\n";
            return -1;
        }
        //else
        t retVal=arr[1];
        arr[1]=arr[currsz];
        --currsz;
        maxHeapify(1);
        cout<<"Max: "<<retVal<<" has been extracted.\n";
        return retVal;
    }
    void IncreaseKey(int i,t newKey)
    {
        if(newKey<arr[i])
        {
            cout<<"New key is not larger than the previous key\n";
            return;
        }
        //in this function,descendent tree will always be OK by definition,upper(ancestor) tree might be destorted( see //else ... )
        t keyOfParent=arr[parent(i)];
        if(newKey<keyOfParent)
        {
            arr[i]=newKey;
            cout<<"Key increased!"<<endl;
            return;
        }
        //else
        arr[i]=newKey;
        cout<<"Key increased!"<<endl;
        heapifyUp(i);
    }
    void DecreaseKey(int i,t newKey)
    {
        if(newKey>arr[i])
        {
            cout<<"New key is not smaller than the previous key\n";
            return;
        }
        //in this function,ancestor tree will always be OK by definition,lower(descendent) tree might be destorted( see //else ... )
        t keyOfLeftChild=arr[2*i];
        t keyOfRightChild=arr[2*i+1];
        if(newKey>keyOfLeftChild && newKey>keyOfRightChild)
        {
            //then there is no problem
            arr[i]=newKey;
            cout<<"Key decreased!"<<endl;
            return;
        }
        //else
        //we have to heapifyDown
        arr[i]=newKey;
        cout<<"Key decreased!"<<endl;
        maxHeapify(i);
    }
    void Sort()
    {
        //we will just extractMAX and push it to the end of the array
        //and then we will decrease the size of the heap by 1
        int len=currsz;
        while(currsz>0)
        {
           t x=ExtractMaxSilent();
           arr[currsz+1]=x;
        }
        cout<<"No of elements: "<<len<<endl;
        int lim=1;
        for(int i=1;i<=len;i++)
        {
            if(i==1)
            {
                cout<<arr[i]<<endl;
                lim*=2;
                continue;
            }
            cout<<arr[i]<<"\t";
            if(i==2*lim-1)
                {
                    lim*=2;
                    cout<<endl;
                }
        }
        cout<<endl;
    }
    void Print()
    {
        cout<<"No of elements: "<<currsz<<endl;
        int lim=1;
        for(int i=1;i<=currsz;i++)
        {
            if(i==1)
            {
                cout<<arr[i]<<endl;
                lim*=2;
                continue;
            }
            cout<<arr[i]<<"\t";
            if(i==2*lim-1)
                {
                    lim*=2;
                    cout<<endl;
                }
        }
        cout<<endl;
    }
    bool isEmpty()
    {
        if(currsz>0)
            return false;
        //else
        return true;
    }
//    bool operator<()

};


#endif // HEAP_H_INCLUDED
