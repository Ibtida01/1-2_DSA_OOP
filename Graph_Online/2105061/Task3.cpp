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
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
int dx[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int steps[100][100];
int visited[100][100];
int n,m,q;
vector<pair<int,int>> source;//source[i] is the starting cell of i_th rider
vector<int> kv;//vector k for each k-rider(i_th)
//int grid[8][8];
pair<int,int> target;
bool valid(pair<int,int> p)
{
    if((p.first>=0 && p.first<n) && (p.second>=0 && p.second<m) && visited[p.first][p.second]==0)
        return true;
    //else
    return false;
}

int decision()
{
    int sum=0,minimum=INT_MAX;
    int ans[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans[i][j]=-1;
    bool isReachable=true;
    for(int i=0; i<q; i++)
    {
        if(steps[source[i].first][source[i].second]!=INT_MAX)
            sum+=ceil(steps[source[i].first][source[i].second]*1.0/kv[i]);
        else
        {
            isReachable=false;
            break;
        }
    }
    //checking each cell for all k riders
    if(isReachable==true)
        return sum;
    else return -1;
}

void bfs(pair<int,int> src)
{
    //cout<<"ns"<<endl;
    visited[src.first][src.second]=1;
    steps[src.first][src.second]=0;
    queue<pair<int,int>> q;
    q.push(src);
    while(q.empty()==false)
    {
        pair<int,int> p=q.front();
        q.pop();
        //visited[p.first][p.second]=1;
        for(int j=0; j<8; j++)
        {
            int x=p.first+dx[j];
            int y=p.second+dy[j];
            pair<int,int> currentCell;
            currentCell.first=x;
            currentCell.second=y;
            if(valid(currentCell))
            {
                visited[currentCell.first][currentCell.second]=1;
                steps[currentCell.first][currentCell.second]=steps[p.first][p.second]+1;
                q.push(currentCell);
            }

        }
    }
}
void solve()
{
    int tx,ty;
    cin>>n>>m>>q;


    int x,y,k;
    for(int i=0; i<q; i++)
    {
        cin>>x>>y>>k;
        source.push_back(make_pair(x,y));
        kv.push_back(k);
    }
    cin>>tx>>ty;
    target.first=tx;
    target.second=ty;
    //initializing the visited array to 0,means not visited
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<m; k++)
        {
            // cout<<"inner"<<endl;
            visited[j][k]=0;
            steps[j][k]=INT_MAX;
        }
    }
    //cout<<"done vi"<<endl;
    //running BFS for the i_th rider with k jump ability
    bfs(target);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<steps[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<decision()<<endl;;
}

int main()
{
    //freopen("in2.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
// int t;
// cin >> t;
// while (t--)
    solve();
}
