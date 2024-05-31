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

const int N=1e7+2;
ll spf[N];

void calc(){
     for(int i=2;i<N;i++){
          if(spf[i]==0){
               for(int j=i;j<N;j+=i){
                    if(spf[j]==0) spf[j]=i;
               }
          }
     }
}

ll convert(string s){
     if(s[0]=='0') return -1;
     ll num=0;
     for(int i=0;i<sz(s);i++){
         num=num*10+(s[i]-'0');
     }
     return num;
}

void dk(){
     string a,b;
     cin>>a>>b;
     set<ll>sta,stb;
     sort(all(a));
     sort(all(b));
     do{
           ll num=convert(a);
           if(num!=-1) sta.insert(num);
     }while(next_permutation(all(a)));
     do{
           ll num=convert(b);
           if(num!=-1) stb.insert(num);
     }while(next_permutation(all(b)));

     map<ll,ll>mp;
     for(auto i:sta){
          ll num=i;
          while(num!=1){
               mp[spf[num]]++;
               num/=spf[num];
          }
     }
     ll ans=1;
     for(auto i:stb){
          ll num=i;
          while(num!=1){
               if(mp[spf[num]]){
                    ans=max(ans,spf[num]);
               }
               num/=spf[num];
          }
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    calc();
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   