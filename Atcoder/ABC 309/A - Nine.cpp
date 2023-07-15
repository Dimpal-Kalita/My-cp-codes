/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    int n,m;
    cin>>n>>m;
    rep(i,0,3){
        rep(j,0,2){
            if(v[i][j]==n and v[i][j+1]==m){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    
    cout<<"No"<<endl;
    return;
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}
