/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 10:36:45
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

string least_rotation(string s){
     s += s;
     int n = s.size();
     int i = 0, ans = 0;
     while(i < n/2){
          ans = i;
          int j = i + 1, k = i;
          while(j < n && s[k] <= s[j]){
               if(s[k] < s[j])
                    k = i;
               else
                    k++;
               j++;
          }
          while(i <= k)
               i += j - k;
     }
     return s.substr(ans, n/2);
}

void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     cout<<least_rotation(s)<<endl;
}



int main()
{ 
    fast_io;
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}