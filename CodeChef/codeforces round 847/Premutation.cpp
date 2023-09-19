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
     vector<vector<ll>> v(n, vector<ll>(n-1));
     for(int i=0;i<n;i++) inp(v[i]);
    
     map<ll,ll>mp;
     for(int i=0;i<n;i++){
        mp[v[i][0]]++;
     }
     ll dif=0;
     vector<ll> ans(n);
     for(int i=0;i<n;i++){
        if(mp[v[i][0]]==1){
            for(int j=0;j<n-1;j++){
                ans[j+1]=v[i][j];
            }
            break;
        }
     }
     for(auto it: mp){
        if(it.S>1) ans[0]=it.F;
     }
     for(auto it:ans) cout<<it<<" ";
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