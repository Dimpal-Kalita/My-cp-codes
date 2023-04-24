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
     ll  a, b, c;
     cin>>a>>b>>c;

     ll f=0, s=0;
     ll ans=0;
     for(ll i=31;i>=0;i--){
        ll x= (1<<i)&a;
        ll y= (1<<i)&b;
        ll z= (1<<i)&c;

        if(x==y && y==z) continue;
        if(z==0){
            if(x==0 && y==1 && f==0){
                cout<<-1<<endl;
                return;
            }
            ans+= (1<<i);
            f=1;
        }
        else if(f==1){
            if(x==1 && y==0){
                ans+= 1<<i;
            }
        }
     }
     
     if((a^ans)<(b^ans) && (b^ans)<(c^ans)){
        cout<<ans<<endl;
        return;
     }
     cout<<-1<<endl;

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