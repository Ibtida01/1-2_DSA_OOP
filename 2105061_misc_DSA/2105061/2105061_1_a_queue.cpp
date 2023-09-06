#include "2105061_1_a_queue.h"
#include<iostream>

 void lst::insrt(int item)
 {
     if(currentsz+1>sz)
     {
         listarr=(int* )realloc(listarr,(2*sz*sizeof(int)));
         sz=sz*2;
     }
     for(int i=currentsz;i>curpos;i--)
     {
         listarr[i]=listarr[i-1];
         //left shifting
     }
     listarr[curpos]=item;
     ++currentsz;
     //print();
 }

 int lst::rmv()
 {
     if(currentsz==0)
     {
         cout<<"error!list is empty\n";
         //print();
         return -1;
     }
     if(curpos==currentsz)
     {
         cout<<"error!nothing to remove\n";
         //print();
         return -1;
     }
     int retval=listarr[curpos];
     for(int i=curpos;i<=currentsz-2;i++)
     {
         listarr[i]=listarr[i+1];
     }
     --currentsz;
     //print();
     return retval;
 }
 void lst::moveToStart()
 {
     curpos=0;
     //print();
 }
 void lst::moveToEnd()
 {
     curpos=currentsz-1;
     //print();
 }
 void lst::prev()
 {
     if(curpos>0)
        --curpos;
     //else do nothing
     //print();
 }
 void lst::nxt()
 {
     if(curpos==currentsz)
     {
         //do nothing
         //print();
         return;
     }
     //else
     ++curpos;
     //print();
 }
 int lst::length()
 {
     //print();
     return currentsz;
 }
 int lst::currPos()
 {
     //print();
     return curpos;
 }
 void lst::moveToPos(int pos)
 {
     if(pos>=0 && pos<currentsz)
     {
         curpos=pos;
         //print();
     }
    //else do nothing
 }
 int lst::getValue()
 {
     //print();
     return listarr[curpos];
 }
 void lst::print()
 {
     cout<<"< ";
     for(int i=0;i<currentsz;i++)
     {
         if(i==curpos)
            cout<<" | ";
         cout<<listarr[i]<<" ";
     }
     cout<<" >"<<endl;
 }
