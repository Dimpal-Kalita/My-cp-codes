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
     ll n;
     cin>>n;
     string s;
     cin>>s;
     vector<char> ev, od;
     for(int i=0;i<n;i++){
        if(i%2) od.pb(s[i]);
        else ev.pb(s[i]);
     }
     sort(all(ev));
     sort(all(od));

     for(int i=0;i<n;i++){
        if(i%2){
            if(binary_search(all(ev),s[i])){
                cout<<"NO"<<endl;
                return;
            }
        }
        else{
            if(binary_search(all(od),s[i])){
                cout<<"NO"<<endl;
                return;
            }
        }
     }
        cout<<"YES"<<endl;
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