 /**
 *
 * author: Dimpal Kalita",
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



map<ll, char> mp={{3,'7'},{6,'9'}};
void dk(){
      ll n,k;
      cin>>n>>k;
      ll x=n, y=k;
      string ans="";
      while(x>=2 and y){
      	ans+='1';
      	x-=2;
      	y--;
      }
  
      for(auto &it:ans){
      		x+=2;
      		if(x>=6){
      			it='9';
      			x-=6;
      		}else if(x>=3){
      			it='7';
      			x-=3;
      		}else{
      			x-=2;
      		}
      }
      for(auto it:ans){
      	cout<<it;
      }
      cout<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}