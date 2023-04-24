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


ll n, m,indi,indj,target1,target2;

map<pair<pair<ll,ll>,ll>,ll>mp;
ll ct=0;

ll recur(ll i, ll j, ll dir){
    ct++;
    if(i==target1 && j==target2) return 0;
    if(ct>20*n*m) return -1e9;
    ll val=0;
    if(dir==0){
        if(i+1==n+1 && j+1==m+1){
            val+=recur(i,j,1)+1;
        }
        else if(i+1==n+1){
            val+=recur(i,j,2)+1;
        }
        else if(j+1==m+1){
            val+=recur(i,j,3)+1;
        }
        else{
            val+=recur(i+1,j+1,0);
        }
    }
    else if(dir==1){
         if(i-1==0 && j-1==0){
            val+=recur(i, j,0)+1;
         }
         else if(i-1==0){
            val+=recur(i, j,3)+1;
         }
         else if(j-1==0){
            val+=recur(i,j,2)+1;
         }
         else{
            val+=recur(i-1, j-1,1);
         }

    }
    else if(dir==2){
        if(i-1==0 && j+1==m+1){
            val+=recur(i, j,3)+1;
        }  
        else if(i-1==0){
            val+=recur(i, j,0)+1;
        }
        else if(j+1==m+1){
            val+=recur(i,j,1)+1;
        }
        else{
            val+=recur(i-1, j+1,2);
        }

    }
    else if(dir==3){
        if(i+1==n+1 && j-1==0){
            val+=recur(i, j,2)+1;
        }
        else if(i+1==n+1){
            val+=recur(i, j,1)+1;
        }
        else if(j-1==0){
            val+=recur(i, j, 0)+1;
        }
        else{ 
            val+=recur(i+1, j-1,3);
        }
    }

    return val;
}



void dk(){
      ct=0;
      string s;
      cin>>n>>m>>indi>>indj>>target1>>target2;
      cin>>s;
      ll dir=0;
      if(s=="DR") dir=0;
      if(s=="DL") dir=3;
      if(s=="UR") dir=2;
      if(s=="UL") dir=1;
    //   cout<<dir<<endl;
      ll val=recur(indi,indj,dir);
      cout<<(val<0?-1:val)<<endl;
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