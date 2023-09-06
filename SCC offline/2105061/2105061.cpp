#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define GREY 1
#define WHITE 0
#define BLACK 2
#define TRUE 53
#define FALSE 54
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
vector<int> adjList[53];//0  to 25 is for a to z, and from 26 to 51 is for ~a to ~z
vector<int> TadjList[53];//transposed adjacency list
int color[53];
vector<int> scc[53];
int dt[53];
int ft[53];
int tme=0;
int ctSCC=0;
int parent[53]={-1};
int value[53]={-1};
//color -1 means the node is not a part of our graph
//color 0,1 2 as they were by convension
stack<int> stk;
void dfs(int node)
{
    dt[node]=++tme;
    color[node]=1;
    for(int i=0;i<adjList[node].size();i++)
    {
        if(color[adjList[node][i]]==0)
        {
            //dt[adjList[node][i]]=++tme;
            dfs(adjList[node][i]);
            //ft[adjList[node][i]]=++tme;
            //stk.push(adjList[node][i]);
        }
    }
    color[node]=2;
    ft[node]=++tme;
    stk.push(node);
}
void dfs2(int node,vector<int>& scc_vector)
{
    //cout<<node<<" ";
    scc_vector.pb(node);
    color[node]=1;
    for(int i=0;i<TadjList[node].size();i++)
    {
        parent[TadjList[node][i]]=node;
        if(color[TadjList[node][i]]==0)
        {
//            pair<int,int> p;
//            p.first=node;
//            p.second=TadjList[node][i];
//            scc[tme++]=p;
            dfs2(TadjList[node][i],scc_vector);
        }
    }
    color[node]=2;
}
bool decision()
{
  for(int i=0;i<ctSCC;i++)
        {
            if(scc[i].size()>1)
            {
                int diff;
                sort(scc[i].begin(),scc[i].end());
                for(int j=0;j<scc[i].size();j++)
                {
                    for(int k=j+1;k<scc[i].size();k++)
                    {
                        diff=scc[i][k]-scc[i][j];
                        if(diff==26 || diff==-26)
                            return false;
                    }
                }
            }
        }
  return true;
}
void inputAnalysis(string s)
{
    if(s.size()==1)
        {
            //just a single variable
            int x=s[0]-'a'+1+26;
            int y=s[0]-'a'+1;
            adjList[x].push_back(y);// ~x -> x
            color[x]=0;
            color[y]=0;
//            x-=26;
//            y=TRUE;
//            adjList[y].push_back(x);// ~FALSE -> a
//            color[x]=0;
//            color[y]=0;
        }
    else if(s.size()==2)
    {
        int x=s[1]-'a'+1;
        int y=x+26;
        adjList[x].pb(y);// x -> ~x
        color[x]=0;
        color[y]=0;
//        x+=26;
//        y=TRUE;
//        adjList[y].pb(x);// ~FALSE -> ~x
    }
    else if(s.size()==3)
    {
        int x=s[0]-'a'+1+26;
        int y=s[2]-'a'+1;
        adjList[x].push_back(y);
        //TadjList[y].pb(x);
        color[x]=0;
        color[y]=0;
        //dbg(x);
        //dbg(y);
        y=y+26;
        x=x-26;
        adjList[y].push_back(x);
        //TadjList[x].pb(y);
        color[x]=0;
        color[y]=0;
    }
    else if(s.size()==4)
    {
        //one has tilde and another doesn't
        if(s[0]=='~')
        {
            //first literal has tilde
            int x=s[1]-'a'+1;
            int y=s[3]-'a'+1;
            adjList[x].push_back(y);// x -> y
            //TadjList[y].pb(x);
            color[x]=0;
            color[y]=0;
            //now contrapositive
            y=y+26;
            x=x+26;
            adjList[y].push_back(x);// ~y -> ~x
           // TadjList[x].pb(y);
            color[x]=0;
            color[y]=0;
        }
        else{
            //2nd literal has tilde
            int y=s[3]-'a'+1;
            int x=s[0]-'a'+1;
            adjList[y].push_back(x);// y -> x
            //TadjList[x].pb(y);
            color[x]=0;
            color[y]=0;
            x=x+26;
            y=y+26;
            adjList[x].push_back(y);// ~x -> ~y
            //TadjList[y].pb(x);
            color[x]=0;
            color[y]=0;
        }
    }
    else{
        //both have tilde
        int x=s[1]-'a'+1;
        int y=s[4]-'a'+1+26;
        adjList[x].pb(y);
        //TadjList[y].pb(x);
        color[x]=0;
        color[y]=0;
        x=x+26;
        y-=26;
        adjList[y].pb(x);
        //TadjList[x].pb(y);
        color[x]=0;
        color[y]=0;
    }
}
void solve()
{
  int n;
  cin>>n;
  getchar();
  string s;
  for(int i=0;i<53;i++)
    color[i]=-1;
  for(int i=0;i<n;i++)
  {
      getline(cin,s);
      inputAnalysis(s);
  }
  //input done
  for(int i=1;i<53;i++)
  {
      if(color[i]==0)
      {
          dfs(i);
      }
  }
  ////////////////////////////////////////DEBUGGING PURPOSE ONLY/////////////////////////////////////////
//  for(int i=1;i<53;i++)
//  {
//      if(color[i]!=-1)
//      {
//            dbg(i);
//            dbg(dt[i]);
//            dbg(ft[i]);
//      }
//  }
//  while(stk.empty()==false)
//  {
//      cout<<stk.top()<<endl;
//      stk.pop();
//  }
  ////////////////////////////////////////DEBUGGING DONE/////////////////////////////////////////////////
  //now transposing the graph
    for(int i=0;i<53;i++)
    {
        for(auto it:adjList[i])
        {
            TadjList[it].pb(i);
        }
    }
    for(int i=0;i<=53;i++)
    {
        if(color[i]!=-1)
            color[i]=0;
    }
    tme=0;
//    for(int i=0;i<53;i++)
//    {
//        scc[i].first=-1;
//        scc[i].second=-1;
//    }
    while(stk.empty()==false)
    {
        int node=stk.top();
        stk.pop();
        if(color[node]==0)
            {
               // cout<<"ssc: ";
               vector<int> tempSCC;
//               temp.first=-1;
//               temp.second=-1;
                dfs2(node,tempSCC);
                scc[ctSCC++]=tempSCC;
            }
    }
    /////////////////////////////////////////////DEBUGGING PURPOSE ONLY___CHECKING SCCs///////////////////////////////////////////////////////////////////
//    cout<<"SCC List:"<<endl;
//    for(int i=0;i<ctSCC;i++)
//        {
//            for(auto it:scc[i])
//                {
//                    if(it>=1 && it<=26)
//                        cout<<(char)(it+'a'-1)<<" ";
//                    else if(it>=27 && it<=52)
//                        cout<<"~"<<(char)(it-26-1+'a')<<" ";
//                }
//            cout<<endl;
//        }
    ////////////////////////////////////////////////////////////DEBUGGING DONE////////////////////////////////////////////////////////////////////////////
    bool isPossible=decision();
    if(isPossible==false)
        {
            cout<<"No assignment possible"<<endl;
            return;
        }
    //else
    for(int i=0;i<53;i++)
        value[i]=-1;
    for(int i=ctSCC;i>=0;i--)
    {
        for(auto it:scc[i])
        {
            if(it>=1 && it<=26 && value[it]==-1)
                {
                    value[it]=1;
                    value[it+26]=2;
                }
            else if(it>=27 && it<=52 && value[it]==-1)
                {
                    value[it-26]=2;
                    value[it]=1;
                }
        }
    }
    for(int i=1;i<=26;i++)
    {
        if(color[i]!=-1)
        {
            if(value[i]==1)
                {
                    cout<<(char)(i-1+'a')<<" true"<<endl;
                }
            else if(value[i]==2)
                {
                    cout<<(char)(i-1+'a')<<" false"<<endl;
                }
        }
    }
}

int main()
{
//    int t;
//    cin>>t;
//    while(t--)
        solve();
}
