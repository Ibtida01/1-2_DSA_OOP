#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define WHITE 0
#define GREY 1
#define BLACK 2
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;

void dfsTraverse(int src,vector<int>* adjList,int* parent,int* color,int* distance)
{
    color[src]=GREY;//src has turned into grey
    //for all the adjacent nodes of src
    for(int i=0;i<adjList[src].size();i++)
    {
        int currentNode=adjList[src][i];
        //cout<<currentNode<<" ";
        if(color[currentNode]==WHITE)
        {
            parent[currentNode]=src;
            distance[currentNode]=distance[src]+1;
            dfsTraverse(currentNode,adjList,parent,color,distance);
        }
    }
    color[src]=BLACK;
}
void dfs(int source,vector<int>* adjList,int vCt,int x)//adjList==adjacency list,we want the shortest path distance between source & x,source & x both user defined
{
   int color[vCt]={WHITE};
   int parent[vCt];
   int distance[vCt];//distance[i]=distance(# of edges in the path) between source and node i,not shortest guaranteed
   for(int i=0;i<vCt;i++)
   {
       distance[i]=INT_MAX;
   }
   distance[source]=0;
   for(int i=0;i<vCt;i++)
   {
       parent[i]=-1;
   }
   dfsTraverse(source,adjList,parent,color,distance);
   int temp=x;
   if(distance[x]!=INT_MAX)
   {
       //path exists from source to x
       cout<<distance[x]<<endl;
       vector<int> path;//reversed btw
       path.push_back(x);//or temp
       while(parent[temp]!=-1)
       {
           path.push_back(parent[temp]);
           temp=parent[temp];
       }
       for(int i=path.size()-1;i>=0;i--)
       {
           cout<<path[i]<<" ";
       }
       cout<<endl;
   }
   else cout<<-1<<endl;
}

void solve()
{
    int e,v;
    cin>>v>>e;
    vector<int> edges[v];
    int x,y;
    //taking graph input
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        edges[x].push_back(y);//indicates a directed edge from x to y
    }
    //graph input taken
    int source,destinationNode;
    // cout<<"Input source node: ";
    cin>>source>>destinationNode;
    //cout<<"Enter destination node: ";
    dfs(source,edges,v,destinationNode);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
// int t;
// cin >> t;
// while (t--)
    solve();
}
/*
possible one test case for testing no path from source to destination:
7 10
0 1
0 2
0 3
1 5
2 5
2 4
3 2
5 4
4 3
6 0
0 6
In the last line, 1st one is src and 2nd one is destination
*/
