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
#define sz(x)             int((x).size());
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

     ll  ans=0;
     for(int it=1;it<n;it++){
        ll x= it;
        ll ct=0, ct2=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(x/i!=i) ct+=2;
                else ct++;
            }
        }

        x=n-it;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(x/i!=i) ct2+=2;
                else ct2++;
            }
        }

        ans+= ct*ct2;

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