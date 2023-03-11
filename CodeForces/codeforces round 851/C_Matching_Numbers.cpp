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
      ll n;
      cin>>n;

      if(n%2==0){
        cout<<"No"<<endl;
        return;
      }
      ll sum= 3*((n+1)/2);
      vector<pll> ans(n);
      ll l=1, r=n-(n/2-1);

      for(int i=0;i<n;i++){
        if(i%2==0){
            ans[i].F= l;
            l++;
        }else{
            ans[i].F=r;
            r++;
        }
      }

      for(int i=0;i<n;i++){
        ans[i].S= sum- ans[i].F;
        sum++;
      }
      cout<<"Yes"<<endl;
      for(auto x: ans){
        cout<<x.F<<" "<<x.S<<endl;
      }

      
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