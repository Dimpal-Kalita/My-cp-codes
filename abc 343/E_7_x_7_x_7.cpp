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





ll allCon(array<ll,3>a,array<ll,3>b){
     ll volume=0;
     array<ll,3> def={8,8,8};
     ll mn=max({a[0],b[0],def[0]});
     ll mx=min({a[0]+7,b[0]+7,def[0]+7});
     ll x=max(0ll,mx-mn);
     mn=max({a[1],b[1],def[1]});
     mx=min({a[1]+7,b[1]+7,def[1]+7});
     ll y=max(0ll,mx-mn);
     mn=max({a[2],b[2],def[2]});
     mx=min({a[2]+7,b[2]+7,def[2]+7});
     ll z=max(0ll,mx-mn);
     volume=x*y*z;
     return volume;
}
ll Twocontain(array<ll,3>a,array<ll,3>b){
     ll volume=0;
     ll mn=max(a[0],b[0]);
     ll mx=min(a[0]+7,b[0]+7);
     ll x=max(0ll,mx-mn);
     mn=max(a[1],b[1]);
     mx=min(a[1]+7,b[1]+7);
     ll y=max(0ll,mx-mn);
     mn=max(a[2],b[2]);
     mx=min(a[2]+7,b[2]+7);
     ll z=max(0ll,mx-mn);
     volume=x*y*z;
     return volume;
}
ll TwoContainDef(array<ll,3>a){
     array<ll,3> def={8,8,8};
     ll volume=0;
     ll mn=max(a[0],def[0]);
     ll mx=min(a[0]+7,def[0]+7);
     ll x=max(0ll,mx-mn);
     mn=max(a[1],def[1]);
     mx=min(a[1]+7,def[1]+7);
     ll y=max(0ll,mx-mn);
     mn=max(a[2],def[2]);
     mx=min(a[2]+7,def[2]+7);
     ll z=max(0ll,mx-mn);
     volume=x*y*z;
     return volume;
}

ll TwoSum1(array<ll,3>a,array<ll,3>b){
     ll volume=Twocontain(a,b)+TwoContainDef(a)+TwoContainDef(b);
     return volume;
}

void dk(){
     ll A,B,C;
     cin>>A>>B>>C; 
     for(int a=0;a<=16;a++){
          for(int b=0;b<=16;b++){
               for(int c=0;c<=16;c++){
                    for(int d=8;d<=23;d++){
                        for(int e=8;e<=23;e++){
                            for(int f=8;f<=23;f++){
                                   array<ll,3> A1={a,b,c};
                                   array<ll,3> A2={d,e,f};
                                   ll x=allCon(A1,A2);
                                   if(x!=C){
                                        continue; 
                                   }
                                   ll y=TwoSum1(A1,A2);
                                   if(y!=B){
                                        continue;
                                   }
                                   ll z=1029-TwoContainDef(A1)-TwoContainDef(A2)+x;
                                   if(z!=A){
                                        continue;
                                   }
                                   cout<<"Yes"<<endl;
                                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<8<<" "<<8<<" "<<8<<endl;
                                   return;
                            }
                        }
                    }
               }
          }
     }
     cout<<"No"<<endl;
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