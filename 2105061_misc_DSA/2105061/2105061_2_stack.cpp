#include "2105061_1_a_queue.h"
using namespace std;
template <typename t>
class stack
{
    int currentsz;
    int top;
    lst<int> q1,q2;
    void print()
    {
        q1.print();
    }
public:
    stack()
    {
        currentsz=0;
        top=0;
    }
    void push(t item)
    {
        q1.enqueue(item);
        ++currentsz;
    }
    t pop()
    {
        t temp;
        while(q1.length()>1)
        {
            temp=q1.dequeue();
            q2.enqueue(temp);
        }
        t retVal=q1.dequeue();
        while(q2.is_empty()!=true)
        {
            temp=q2.dequeue();
            q1.enqueue(temp);
        }
        --currentsz;
        return retVal;
    }
    void clear()
    {
        while(q1.is_empty()!=true)
        {
            q1.dequeue();
        }
        currentsz=0;
    }
    int length()
    {
        return currentsz;
    }
    t topValue()
    {
        return q1.back();
    }
    bool isEmpty()
    {
        if(currentsz==0)
            return true;
        //else
        return false;
    }
};


