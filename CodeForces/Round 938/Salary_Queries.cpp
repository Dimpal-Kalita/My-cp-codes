//Partho Pratim Choudhury 2112003 (par-_-tho)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll          long long
#define ull         unsigned long long
#define lld         long double
#define fr(i,k,n)   for(ll i=k;i<n;i++)
#define rfr(i,n,k)  for(ll i=n;i>=k;i--)
#define inp(v,n)    fr(i,0,n){cin >> v[i];}
#define all(x)      (x).begin(),(x).end()
#define vll         vector<ll>
#define vpll        vector<pair<ll, ll>>
#define ff          first
#define ss          second
#define mll         map<ll,ll>
#define pb          push_back
#define br          '\n'
#define print(a,n)  for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define fbo(k)      find_by_order(k) // returns an iterator to kth element in ordered set (zero based index)
#define ook(k)      order_of_key(k) // counts the elements which are strictly less than key k in ordered set
#define max_pq      priority_queue<ll>
#define min_pq      priority_queue<ll, vll, greater<ll>>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //required to perform set operations with indexing facility

/******************************************Debug Starts************************************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*******************************************Debug Ends*************************************************/

/**************************************Number theory starts********************************************/
const int M=1e9+7;
const int inf = LLONG_MAX;
ll power(ll a, ll b){ ll res=1; while(b>0){ if(b&1){ res=res*a; } a=a*a; b=b>>1; } return res; }

ll modPow(ll x,ll y,ll p){ ll res=1; x=x%p; while (y>0){ if(y&1){ res=(res*x)%p; } y=y>>1; x= (x*x)%p;} return res; }

ll phi(ll n){ ll res=n; for(ll i=2;i*i<=n;i++){ if(n%i==0){ res=res/i; res=res*(i-1);} while(n%i==0){ n=n/i;}} if(n>1){ res=res/n; res=res*(n-1); } return res;}

ll lcm(ll a, ll b){return (a / __gcd(a, b)) * b;}
ll modInv(ll x, ll p){ return modPow(x, p-2, p);}
// ll nCr(int n, ll r){ ll ans = (fact[n] * modInv(fact[r], M) % M * modInv(fact[n - r], M) % M) % M; return ans; }
/****************************************Number theory ends**********************************************/



const int N=6e5;
int bit[N]; // storing the frequency of elements (same as storing for compressed ones)

int n;
void update(int i, int x){
     for(; i <= n; i += (i & (-i))){
          bit[i] += x;
     }
     return;
}

int sum(int i){
     int ans = 0;
     for(; i > 0; i -= (i & (-i))){
          ans += bit[i];
     }
     return ans;
}

int query(ll l, ll r){
     return sum(r) - sum(l-1);
}




struct Q{
    char type;
    int a;
    int b;
};

void solve(){

    // solution 2 using BIT
    ll q;
    cin >> n >> q;

    map<int,int> m;
    vector<int> a(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m[a[i]] = 0;
    }

    vector<Q> qv;
    for(int i = 0; i < q; i++){
        char type;
        cin >> type;
        if(type == '!'){
            ll k, x;
            cin >> k >> x;
            m[x] = 0;
            qv.push_back({'!', k, x});
        }else{
            ll a, b;
            cin >> a >> b;
            m[a] = m[b] = 0;
            qv.push_back({'?', a, b});
        }
    }

    // compressing
    ll cnt = 1;
    for(auto &it:m){
     m[it.first] = cnt++;
    }

    for(int i = 1; i <= n; i++){
        update(m[a[i]], 1);
    }
    for(auto qe : qv){
        if(qe.type == '!'){
            ll k = qe.a;
            ll x = qe.b;
            
            update(m[a[k]], -1);

            update(m[x], 1);

            a[qe.a] = qe.b;
        }else{
            ll l = qe.a;
            ll r = qe.b;
            ll ans = query(m[l], m[r]);
            cout << ans << endl;
        }
    }


    // solution 1 using ordered set  

    // ll n, q;
    // cin >> n >> q;
    // vll a(n+1);
    // ordered_set<pair<ll,ll>> o;
	// fr(i, 1, n + 1) {
	// 	cin >> a[i];
	// 	o.insert({a[i], i});
	// }
	// while(q--){
	// 	char c;
	// 	cin >> c;
	// 	if (c == '!') {
	// 		int x, y;
	// 		cin >> x >> y;
	// 		o.erase({a[x], x});
	// 		a[x] = y;
	// 		o.insert({a[x], x});
	// 	} else {
	// 		int x, y;
	// 		cin >> x >> y;
    //         // by finding order_of_key({i, M}) we are finding the last index of i, by this we can find the number of employees between [a, b] as below.
	// 		cout << o.order_of_key({y, M}) - o.order_of_key({x - 1, M}) << endl;
	// 	}
	// }
    return;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r+",stdin);
        freopen("output.txt","w+",stdout);
        freopen("Error.txt", "w", stderr);
    #endif
    */

    ll t=1;
    // cin>>t;
    for(ll i=1;i<=t;i++){
        solve();
    }
    return 0;
}