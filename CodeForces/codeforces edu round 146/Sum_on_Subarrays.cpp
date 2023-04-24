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
#define sz(x)               ((long long)((x).size()));
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
     ll  n, k;
     cin>>n>>k;

     ll val=0;
     for(int i=1;i<100;i++){
        if((i*(i+1))/2 > k) break;
        val=i;
     }


     ll rest= k-((val*(val+1))/2);

     
     ll ans=1;
     ll count=0;
     for(int i=0;i<rest;i++){
        cout<<2<<" ";
        count++;
     }


     for(int i=rest;i<val;i++){
        cout<<1<<" ";
        ans++;
        count++;
     }

     if(count<n) cout<<-ans<<" ";
     for(int i=val;i<n-1;i++){
        cout<<-1000<<" ";
     }
     cout<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}