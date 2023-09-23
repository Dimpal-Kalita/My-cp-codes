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
     string s;
     cin>>s;
     ll n = s.length();
     if(n==1){
      cout<<0<<endl;
      return;
     }
     if(count(all(s),'B')==0){
      cout<<0<<endl;
      return;
     }
     vl dx;
     ll last=0;
     for(int i = 0 ; i < n-1 ; i ++){
      if(s[i] == 'B' && s[i+1] == 'B'){
        ll an = count(all(s) , 'A');
        cout << an << endl;
        return;
      }
     }
     if(s[0]=='B' || s[n-1]=='B') dx.pb(0);
     for(int i = 0 ; i  < n ; i ++){
      ll cnt = 0;
      ll ind = i;
      while(ind < n && s[ind] == 'A'){
        ind++;
        cnt++;
      }
      if(cnt){
        i=ind-1;
        dx.pb(cnt);
      }
     }
     sort(all(dx));
     ll an = accumulate(all(dx), 0LL)-dx[0];
     cout << an << endl;

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