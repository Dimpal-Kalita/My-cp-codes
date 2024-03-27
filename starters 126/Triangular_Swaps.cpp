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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

ll count(string s,ll n){
     set<string>st;
     for(int i=0;i<n-2;i++){
          string t=s.substr(i,3);
          rotate(t.begin(),t.begin()+1,t.end());
          st.insert(s.substr(0,i)+t+s.substr(i+3));
     }
     return st.size();
}

string generate(){
     ll n=rand(3,10);
     string ans="";
     for(int i=0;i<n;i++){
          ans+=(rand(0,25)+'a');
     }
     return ans;
}
void dk(){
     ll n;
     string s=generate();
     n=s.length();
     cin>>n;
     cin>>s;
     ll ans=0;
     bool flag=1;
     for(int i=0;i+2<n;i++){
          if(i+3<n and s[i]==s[i+1] and s[i+1]==s[i+3] and s[i+3]==s[i]) continue;
          if(s[i]==s[i+1] and s[i+1]==s[i+2]){
               if(flag) ans++;
               flag=0;
               continue;
          }
          ans++;
     }
     // if(ans!=count(s,n)){
     //      cout<<ans<<" "<<count(s,n)<<" ->";
     //      cout<<s<<endl;
     // }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   