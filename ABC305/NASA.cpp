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


vector<int>generate_allPelindrome(int n){
     vector<int>pel;
     for(int i=0;i<n;i++){
           int temp=i;
           int rev=0;
           while(temp>0){
                int rem=temp%10;
                rev=rev*10+rem;
                temp/=10;
           }
           if(rev==i){
                pel.pb(i);
           }
     }
     return pel;
}

vector<int>pelind=generate_allPelindrome((1<<15));

void dk(){
     ll n;
     cin>>n;
     int ans=0;
     vector<int>v(n);
     vector<int> mp(1<<15,0);
     for(auto &it:v){
          cin>>it;
          mp[it]++;
     }
     for(auto it:v){
          for(auto it2:pelind){
               ll x= (it2 ^ it);
               ans+=mp[x];
          }
          mp[it]--;
     }
    cout<<ans<<endl;
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