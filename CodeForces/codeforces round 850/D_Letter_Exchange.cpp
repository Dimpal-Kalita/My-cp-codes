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


typedef struct Str{
    ll b;
    char a;
    ll d;
    char c;
}str;


void dk(){
     ll n;
     string s[n];
     vector<str> ans;
     vector<pair<string, ll>>v1, v2;
     for(int i=0;i<n;i++){
         cin>>s[i];
         set<char> st;
         for(auto it:s[i]){
            st.insert(it);
         }
            if(st.size()==1){
                v1.pb({s[i], i+1});
            }
            else{
                v2.pb({s[i], i+1});
            }
     }
     while(v2.size()>=3){
        ll i= v2.size()-1;
        ll j= v2.size()-2;
        ll k= v2.size()-3;
        ll a, b, c;
        for(auto it:{i, j, k}){
            if(v2[it].F[0]=='a'){
                a=it;
            }
            else if(v2[it].F[0]==v2[it].F[2]){
                b=it;
            }
            else{
                c=it;
            }
        }

        str val= {v2[a].S, v2[a].F[1], v2[b].S, v2[b].F[1]};
        ans.pb(val);
        str val= {v2[b].S, v2[b].F[0], v2[c].S, v2[c].F[0]};
        ans.pb(val);
        str val= {v2[a].S, v2[a].F[0], v2[c].S, v2[c].F[0]};
        ans.pb(val);
        ans.pop_back();
        ans.pop_back();
        ans.pop_back();
     }
     if(v2.size()==2){
        ll i= v2.size()-1;
        ll j= v2.size()-2;
        ll k= v1.size()-1;
        ll a, b, c;
        for(auto it:{i, j, k}){
            if(v2[it].F[0]=='a'){
                a=it;
            }
            else if(v2[it].F[0]==v2[it].F[2]){
                b=it;
            }
            else{
                c=it;
            }
        }

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