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




vector<string> v[27];
int cnt[26];

void dk(){
     string s;
     cin>>s;
     int n=s.size();
     for(int i=0;i<n;i++){
       
          v[s[0]-'a'].pb(s);

          rotate(s.begin(),s.begin()+1,s.end());
     }
     
     double ans=0;

     for(int i=0;i<26;i++){
          if(v[i].size()==0) continue;

          int mx=0;
          for(int j=1;j<n;j++){
               memset(cnt,0,sizeof(cnt));
               for(auto &it:v[i]){
                    cnt[it[j]-'a']++;
               }
               int temp=0;
               for(int k=0;k<26;k++){
                  if(cnt[k]==1)  temp++;
               }
               mx=max(mx,temp);
          }
          ans+=  mx/(double)n;
     }
     cout<<fixed<<setprecision(7);
     cout<<ans;
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