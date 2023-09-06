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


void bfs(int source,vector<int>* adjList,int vCt,int x)//adjList==adjacency list,we want the shortest path distance between source & x,source & x both user defined
{
    //cout<<"vCt is "<<vCt<<endl;
    int color[vCt]= {WHITE}; //all are white
    int distance[vCt];//distance[i] = distance of node i from source node, for s it is 0
    int parent[vCt];
    for (int i = 0; i < vCt; i++)
        distance[i] = INT_MAX; // Initialize with an invalid(like -1,infinity etc.) value
    std::queue<int> q;
    color[source]=GREY;//source is grey
    q.push(source);
    distance[source]=0;
    //cout<<source<<" ";
    parent[source]=-1;
    while(q.empty()==false)
    {
        int currentNode=q.front();
        //cout<<currentNode<<" "; //for printing the BFS traversal order
        q.pop();
        for(int i=0; i<adjList[currentNode].size(); i++)
        {
            if(color[adjList[currentNode][i]]==WHITE)
            {
                q.push(adjList[currentNode][i]);
                color[adjList[currentNode][i]]=GREY;//grey
                distance[adjList[currentNode][i]]=distance[currentNode]+1;
                parent[adjList[currentNode][i]]=currentNode;
                // cout<<"present node distance is "<<distance[adjList[currentNode][i]]<<" and parent is "<<distance[currentNode]<<endl;
            }
        }
        color[currentNode]=BLACK;//black
    }
    //cout<<endl;
    if(distance[x]!=INT_MAX)
            {
                cout<<distance[x]<<endl;;
                int temp=x;
                vector<int> path;//reversed path btw
                path.push_back(x);
                while(parent[temp]!=-1)
                {
                    int insertNode=parent[temp];
                    path.push_back(insertNode);
                    temp=insertNode;
                }
                for(int i=path.size()-1; i>=0; i--)
                {
                    cout<<path[i]<<" ";
                }
                cout<<endl;
            }
            else cout<<-1<<endl;//this condition will ONLY satisfy if the graph is directed
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
    bfs(source,edges,v,destinationNode);
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
// int t;
// cin >> t;
// while (t--)
    solve();
}
