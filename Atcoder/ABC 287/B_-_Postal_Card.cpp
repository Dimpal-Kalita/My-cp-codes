// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




void dk(){
     int n, m;
     cin>>n>>m;
     map<string, int>mp, tm;

     for(int i=0;i<n;i++){
        string s;
        cin>>s;
        string t="";
        for(int i=3;i<6;i++){
            t+=s[i];
        }
        tm[t]++;
     } 

      for(int i=0;i<m;i++){
        string t;
        cin>>t;
        mp[t]++;
     }

     int ans=0;
     for(auto it: tm){
        if(mp[it.F]>0) ans+=it.S;
     }
     cout<<ans<<endl;


}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}