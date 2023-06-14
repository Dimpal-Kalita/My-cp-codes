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



map<char,pll> vp= {{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}}};

void dk(){
     ll n,m,k;
     cin>>n>>m>>k;
     string s[n];
     pll start;

     rep(i,0,n) {
          cin>>s[i];
          rep(j,0,m){
               if(s[i][j]=='X') start={i,j};
          }
     }

     if(k%2){
          cout<<"IMPOSSIBLE"<<endl;
          return;
     }
     vector<vl>dist(n,vl(m,INT_MAX)),vis(n,vl(m,0));
     
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     // queue<pair<string,pll>>pq;

     string ans="";
     pq.push(start);
     vector<vector<ll>>dis(n,vector<ll>(m,1e8));
     dis[start.F][start.S]=0;

     while(!pq.empty()){
          pll cur=pq.top();
          pq.pop();

          for(auto it:vp){

               ll newF=cur.F+it.S.F,newS=cur.S+it.S.S;
               if(newF<0 or newF>=n or newS<0 or newS>=m or  s[newF][newS]=='*') continue;
               
               if(dis[newF][newS]>dis[cur.F][cur.S]+1){
                    pq.push({newF,newS});
                    dis[newF][newS]= dis[cur.F][cur.S]+1;
               }
          
          }
     }

     pll cur=start;
     while(k){
          // cerr<<ans<<endl;
          bool flag=0;
          for(auto it:vp){
               ll newF=cur.F+it.S.F,newS=cur.S+it.S.S;
               if(newF<0 or newF>=n or newS<0 or newS>=m or  s[newF][newS]=='*' or dis[newF][newS]>k) continue;                        
               ans+=it.F;
               cur.F=newF,cur.S=newS;
               flag=1;
               break;
          }

          if(!flag){
               cout<<"IMPOSSIBLE"<<endl;
               return;
          }
          k--;
     }
     cout<<ans<<endl;

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