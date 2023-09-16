/**
 * 
 * author: Dimpal Kalita
 * date: 30/08/2023 09:50:19
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

int perfectSubstring(string s,int k){
    int ct[10]={0};
    int n=s.length();
    int ans=0;

    for(int i=0,j=0;i<n;i++){
         ct[s[i]-'0']++;
         while(j<i && *max_element(ct,ct+10)>k){
              ct[s[j]-'0']--;
              j++;
         }

         bool flag=1;
         for(int i=0;i<10;i++){
              if(ct[i] && ct[i]!=k){
                   flag=0;
                   break;
              }
         }
         if(flag){
            cout<<j<<" "<<i<<endl;

         }

    }
    return ans;
}



void dk(){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    cout<<perfectSubstring(s,k)<<endl;
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
