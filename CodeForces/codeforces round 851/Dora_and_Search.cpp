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
      vector<ll> v(n);
      inp(v);
      ll mn=1,mx=n;
      ll l=0, r=n-1;
      while(l<r && mn<mx){

        if(v[l]==mn){
            l++;
            mn++;
            continue;
        }
        if(v[r]==mx){
            r--;
            mx--;
            continue;
        }
        if(v[r]==mn){
            mn++;
            r--;
            continue;
        }
        if(v[l]==mx){
            l++;
            mx--;
            continue;
        }
        cout<<l+1<<" "<<r+1<<endl;  
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