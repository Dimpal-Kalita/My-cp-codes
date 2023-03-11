// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t) {cerr << t;}
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



struct DSU{
    vector<ll> parent;
    vector<ll> size;
    ll total_components;

    void init(ll n){
        parent.resize(n);
        size.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        total_components=n;
    }

    ll get(ll a){
        if(a==parent[a]) return a;
        return parent[a]=get(parent[a]);
    }
    ll getsize(ll a){
        return size[get(a)];
    }

    void unite(ll a,ll b){
        a=get(a);
        b=get(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
            total_components--;
        }
    }
};



bool check_reflex(vector<vector<int>>v){
	int n=v.size();


	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){

			if(i==j && v[i][j]!=0) return 0;
			if(v[i][j]!=v[j][i]) return 0;

		}

	}

	return 1;
}



struct Edge{
	int u, v, w;
	bool operator<(const Edge&other){
		return w<other.w;
	}
};




vector<vector<pii>> adj;
vector<vector<int>>v;


bool dfs(int i,int node=0, int par=-1,int dist=0){

	if(v[i][node]!=dist){
		cout<<i<<" "<<node<<" "<<dist<<" /";
		return 0;
	}

	bool re=1;
	for(auto j:adj[node]){
		if(j.F==par) continue;
        cout<<j.F<<" "<<dist<<" "<<j.S<<" /";
		re&= dfs(i,j.F, node, dist+j.S);
	}

	return re;
}


void dk(){
      int n;
      cin>>n;
      v.resize(n, vector<int> (n,0));
      adj.resize(n+1);
      for(int i=0;i<n;i++){
      	for(int j=0;j<n;j++){
      		cin>>v[i][j];
      	}
      }

      if(!check_reflex(v)){
      	cout<<"NO"<<endl;
      	return;
      }

      vector<Edge> adj1;

      for(int i=0;i<n;i++){
      	for(int j=i+1;j<n;j++){
      		if(v[i][j]>0) adj1.pb({i, j,v[i][j]});
      	}
      }


      DSU dsu;
      dsu.init(n);

      sort(all(adj1));
  
      for(auto it:adj1){
      	if(dsu.get(it.u)!=dsu.get(it.v)){
           	dsu.unite(it.u, it.v);
            cout<<it.u<<" "<<it.v<<endl;
      		adj[it.u].pb({it.v, it.w});
      		adj[it.v].pb({it.v, it.w});
      	}
      }
      debug(adj)
      for(int i=0;i<n;i++){
      	if(!dfs(i)){
      		
      		cout<<"NO"<<endl;
      		return;
      	}
      }


      cout<<"YES"<<endl;




      


}




int main()
{ 
    fast_io;
    
    //#ifndef IGNOREME
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif
    
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}