#include <set>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define MAX 1000000000
#define pii pair<int,int>
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
vector<pii> trees;
int n;
set<pii> ans;
//int sideDetermine(pii leftEnd,pii rightEnd,pii p)
//{
//    cout<<"1"<<endl;
//    double a=(rightEnd.second-leftEnd.second)/(1.0*(rightEnd.first-leftEnd.first));
//    //the eqn of the line is ax-y+yL-a*xL=0
//    cout<<"2"<<endl;
//    double c=leftEnd.second-a*leftEnd.first;
//    cout<<"3"<<endl;
//    int x=p.first,y=p.second;
//    cout<<"4"<<endl;
//    double flag=a*x-y+c;
//    cout<<"5"<<endl;
//    if(flag>0)
//        return 1;
//    else return -1;
//}
//
double dis(pii leftEnd,pii rightEnd,pii p)
{//leftEnd is the left end of the line
    //same for right end
    double a=(rightEnd.second-leftEnd.second)/(1.0*(rightEnd.first-leftEnd.first));
    //the eqn of the line is ax-y+yL-a*xL=0
    double c=leftEnd.second-a*leftEnd.first;
    int x=p.first,y=p.second;
    double d=abs(a*x-y+c)/sqrt(a*a+1);
    return d;
}

int sideDetermine(pii p1,pii p2,pii p)
{
    int flag=(p.second-p1.second)*(p2.first-p1.first)-(p2.second-p1.second)*(p.first-p1.first);
    if(flag>0)
        return 1;
    else if(flag<0)
        return -1;
    else return 0;
}

void quickHull(pii p1,pii p2,int side)
{
    //cout<<"quickHull starts"<<endl;
    //+1 means upper side
    //-1 means lower side
    int foundIdx=-1,mxdis=-1,currdis;
    for(int i=0;i<n;i++)
    {
        currdis=dis(p1,p2,trees[i]);
        if(sideDetermine(p1,p2,trees[i])==side && currdis>mxdis)
        {
            foundIdx=i;
            mxdis=currdis;
        }
    }
    if(foundIdx==-1)
    {
        //no points are found
        ans.insert(p1);
        ans.insert(p2);
        return;
        //cout<<"returning from if block"<<endl;
    }
    quickHull(trees[foundIdx],p1,-sideDetermine(trees[foundIdx],p1,p2));
    quickHull(trees[foundIdx],p2,-sideDetermine(trees[foundIdx],p2,p1));
    //cout<<"returning from quickHull"<<endl;
}
void findCH()
{
    //cout<<"findCH begins"<<endl;
    int mxidx=-1,minidx=-1;
    int min_X=INT_MAX,max_X=INT_MIN;
    for(int i=0;i<trees.size();i++)
    {
        if(trees[i].first<min_X)
        {
            min_X=trees[i].first;
            minidx=i;
        }
        if(trees[i].first>max_X)
        {
            max_X=trees[i].first;
            mxidx=i;
        }
    }
    //cout<<"found min and max"<<endl;
    quickHull(trees[mxidx],trees[minidx],+1);
    quickHull(trees[mxidx],trees[minidx],-1);
}
void solve()
{

    cin>>n;
    int x,y;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        trees.pb(make_pair(x,y));
    }
    //sort(trees.begin(),trees.end());
//  for(auto it:trees)
//  {
//      cout<<it.first<<" "<<it.second<<endl;
//  }
    findCH();
    for(auto it:ans)
        cout<<it.first<<" "<<it.second<<endl;

}

int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    int t;
//    cin >> t;
//    while (t--)
    solve();
}

