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

void solve()
{

   int n;
   cin>>n;
   vector<int> atv,dtv;//atv==arrival time vector and dtv=departure time vector
   int atime,dtime;//atime= arrival time and dtime=departure time
   for(int i=0;i<n;i++)
   {
       cin>>atime>>dtime;
       atv.pb(atime);
       dtv.pb(dtime);
   }
   sort(atv.begin(),atv.end());
   sort(dtv.begin(),dtv.end());
   int currPtct=0,allTimesMax=-1;
   int i=0,j=0;
   for(i=0,j=0;i<n && j<n;)
   {
       if(atv[i]<dtv[j])
       {
           ++currPtct;
           allTimesMax=max(allTimesMax,currPtct);
           ++i;
       }
       else if(atv[i]>dtv[j])
       {
           --currPtct;
           ++j;
       }
       else
       {
           //both are same
           ++i,++j;
           //++currPtct;
           //--currPtct;
           //no use
       }
   }
   cout<<allTimesMax<<endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
//    int t;
//    cin >> t;
//    while (t--)
    solve();
}
