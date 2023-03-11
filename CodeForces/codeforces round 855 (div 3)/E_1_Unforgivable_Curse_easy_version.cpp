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
#define size(x)             int((x).size());
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



bool is_equal(string a, string b){
    sort(all(a));
    sort(all(b));
    return a==b;
}


void dk(){
     ll n, k;
     cin>>n>>k;
     string a, b;
     cin>>a>>b; 
     if(!is_equal(a, b)){
        cout<<"NO"<<endl;
        return;
     }

     if(n>=2*k){
        cout<<"YES"<<endl;
        return;
     }


     vector<ll> vis(n+1, 0);

     for(int i=0;i<n;i++){
        if(i+k<n) vis[i+k]++, vis[i]++;
        if(i+k+1<n) vis[i+k+1]++, vis[i]++;
     }

     for(int i=0;i<n;i++){
        if(!vis[i]){
            if(a[i]!=b[i]){
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