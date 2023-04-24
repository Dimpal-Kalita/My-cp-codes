// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


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
     ll n, s1, s2, i1=1, i2=1;
     cin>>n>>s1>>s2;
     priority_queue<pll> pq;
     for(int i=0;i<n;i++){
         ll x;
         cin>>x;
         pq.push({x, i});
     }

     vector<ll> v1, v2;
     while(!pq.empty()){
        pll p= pq.top();
        pq.pop();
        if(p.F*i1*s1<p.F*i2*s2){
            v1.pb(p.S);
            i1++;
        }
        else{
            v2.pb(p.S);
            i2++;
        }
     }

     cout<<v1.size()<<" ";
     for(auto x:v1){
        cout<<x+1<<" ";
     }
     cout<<endl;
     cout<<v2.size()<<" ";

     for(auto x:v2){
        cout<<x+1<<" ";
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