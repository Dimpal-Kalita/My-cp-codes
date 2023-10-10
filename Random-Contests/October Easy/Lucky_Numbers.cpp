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
     ll n;
     cin>>n;
     string s=to_string(n);
     ll pos=20;
     for(int i=0;i<sz(s);i++){
          if(s[i]%2==0){
               pos=i;
               break;
          }
     }
     if(pos==20){
          cout<<n<<endl;
          return;
     }
     ll realpos=pos;
     string t=s;
     if(s[pos]=='0'){
          for(int i=pos;i>=0;i--){
               if(i==0 and t[i]=='1'){
                    t.erase(t.begin());
                    break;
               }
               else{
                    if(t[i]=='0'){
                         t[i]='9';
                    }else{
                         t[i]-=2;
                         break;
                    }
               }
          }
          pos--;
     }else{
          t[pos]--;
     }
     for(int i=pos+1;i<sz(s);i++){
          t[i]='9';
     }
     ll A=0;
     for(int i=0;i<sz(t);i++){
          A=A*10+(t[i]-'0');
     }
     t=s;

     pos=realpos;
     t[pos]++;
     for(int i=pos+1;i<sz(s);i++){
          t[i]='1';
     }
     ll B=stoll(t);
     if(abs(n-A)<=abs(n-B)) cout<<A<<endl;
     else cout<<B<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   