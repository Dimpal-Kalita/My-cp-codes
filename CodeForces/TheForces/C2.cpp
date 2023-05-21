 /**
 *
 * author: Dimpal Kalita",
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


void dk(){
      ll n,x;
      cin>>n>>x;
      ll tot_sum= n*(2*n+1),sum=2*n+1;
      vl ans(2*n);
      ans[0]=x;
      ans[1]= sum-x;

      for(ll y=tot_sum-x;y>2*n;y-= (n-1)){

      	  ll sum2= y/(n-1);
      	  vl vis(2*n+1,0),v(2*n,0);
      	  vis[x]=1;
      	  vis[sum-x]=1;
      	  v[0]=1;
      	  v[1]=sum-x;
      	  bool flag=1;
      	  v[2*n-1]=  tot_sum- sum2*(n-1);
      	  v[2*n-2]= sum- v[2*n-1];
      	  vis[2*n-1]=1;
      	  vis[2*n-2]=1;
      	  for(int i=0;i<2*n-3;i++){
      	  	if(i%2==0){
      	  		v[i+1]= sum-v[i];

      	  	}
      	  	else{
      	  		v[i+1]=sum2-v[i];

      	  	}

      	  	if(vis[v[i+1]]){
      	  			flag=0;
      	  			break;
      	  		}
      	  		vis[v[i+1]]=1;
      	  }

      	  if(flag==1){
      	  	for(auto it:v){
      	  		cout<<it<<" ";
      	  	}
      	  	cout<<endl;
      	  	return;
      	  }

      }

      cout<<-1<<endl;
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