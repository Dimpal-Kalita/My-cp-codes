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






/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/




void dk(){
      ll n,x;
      cin>>n>>x;
      ll tot_sum= n*(2*n+1),sum=2*n+1;
      vl ans(2*n);
      ans[0]=x;
      ans[1]= sum-x;
     //  ll xt=0;
      for(ll y=0;y<=3;y++){
      	// xt++;
          //   if(sum2%2==0) continue;
          //   cerr<<y<<" "<<sum2*(n-1)<<" ";
          //   if(sum2<=2*n) break;
      	  vl vis(2*n+1,0),v(2*n,0);
      	  vis[x]=1;
      	  vis[sum-x]=1;
      	  v[0]=x;
      	  v[1]=sum-x;
      	  bool flag=1;
      	  v[2*n-1]=  tot_sum-x-sum2*(n-1);
      	  v[2*n-2]= sum- v[2*n-1];
            if(v[2*n-2]<=0) continue;

            if(vis[v[2*n-1]] || vis[v[2*n-2]]) continue;
      	  vis[v[2*n-1]]=1;
      	  vis[v[2*n-2]]=1;
      	//   debug(v);
      	  for(int i=0;i<2*n-1;i++){
               if(v[i+1]!=0) continue;
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
          //   debug(v);
      	  if(flag==1){
      	  	for(auto it:v){
      	  		cout<<it<<" ";
      	  	}
      	  	cout<<endl;
      	  	return;
      	  }

      }
     //  cout<<xt<<" ";
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