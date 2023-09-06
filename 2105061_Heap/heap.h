#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include<iostream>

class Heap
{
private:
    int* arr;
    int currsz;
    int SIZE;
    int parent(int idx)
    {
        return (i/2);//same as taking floor
    }
    void maxHeapify(int i)
    {
        int l,r;
        l=2*i;//l is the left child of i
        r=2*i+1;//right child of i
        int largest;//it might seem that we can initiate largest with i, i.e largest=i
        //but what if the leftchild simply DNE?i.e l > currsz ??so we need the following code block
        if(l <= currsz && arr[i] < arr[l])
            largest=l;
        else largest=i;
        if(r <= currsz && arr[l] < arr[r])//if right child exists AND right child has higher value
            largest=r;
        if(i!=largest) // if a[i] is not the largest among its children ...
        {
            swap(arr[i], arr[largest]);
            i=largest;
            maxHeapify(i);
        }
    }
public:
    Heap(int sz)
    {
        arr=new int[sz+1];
        currsz=0;
        SIZE=sz;
    }
    void insert(int x)
    {
        if(currsz==SIZE)
        {
            cout<<"Overflow!\n";
            return;
        }
        //else
        arr[++currsz]=x;
        //heapify UP
        int i=currsz-1,p=parent(i);//p=parent if index i
        while(i>=1 && arr[p]<arr[i])
        {
            swap(arr[i],arr[p]);
            i=p;
            p=parent(i);
        }
    }
    int getMax()
    {
        if(currsz>0)
            return arr[1];
        else
        {
            cout<<"Heap is empty!";
            return -1;
        }
    }
    int deleleKey()
    {
        if(currsz==0)
        {
            cout<<"Heap is empty!\n";
            return -1;
        }
        //else
        int retVal=arr[1];
        arr[1]=arr[currsz];
        --currsz;
        maxHeapify(arr,1);
        return retVal;
    }
    void heapsort(vector<int>& v)
    {
        //here v is a heap
        int vectorsz=v.size();
        int poped=v.deleteKey();
        v[vectorsz]=
    }
    bool isEmpty()
    {
        if(currsz>0)
            return true;
            //else
        return false;
    }
};


#endif // HEAP_H_INCLUDED
