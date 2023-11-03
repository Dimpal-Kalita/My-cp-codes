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




template<class T> struct BIT {
  vector<T> s;
  int n;
  BIT(int n): s(n + 1), n(n) {}
  void update(int i, T v) {
    for (i++; i <= n; i += i & -i) s[i] += v;
  }
  T query(int i) { // EXCLUSIVE interval [0, i)
    T ans = 0;
    for (; i; i -= i & -i) ans += s[i];
    return ans;
  } // INCLUSIVE-EXCLUSIVE interval [l, r)
  T query(int l, int r) { return query(r) - query(l); }
  int kth(T k) { // 0-indexed, returns n if k > sum of tree
    if (k < 0) return -1;
    int i = 0;
    for (int pw = 1 << __lg(n); pw; pw >>= 1)
      if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
    return i;
  }
};


vector<ll> CountDiv(ll n){
    vector<ll>prime(n+1),spf(n+1),count(n+1);
    for(ll i=2;i<=n;i++){
        if(!prime[i]){
            spf[i]=i;
            for(ll j=i;j<=n;j+=i){
                prime[j]=1;
                spf[j]=i;
            }
        }
    }
    for(ll i=2;i<=n;i++){
        ll x=i;
        map<ll,ll>mp;
        while(x!=1){
            mp[spf[x]]++;
            x/=spf[x];
        }
        ll ans=1;
        for(auto i:mp){
            ans*=(i.S+1);
        }
        count[i]=ans;
    }
    return count;
}

vector<ll>prime=CountDiv(1e6+1);

void dk(){
  ll n,q;
  cin>>n>>q;
  vl v(n);
  inp(v);
  BIT<ll>bit(n);
  set<ll>st;
  for(int i=0;i<n;i++){
      bit.update(i,v[i]);
     if(v[i]>2) st.insert(i);
  }
  st.insert(n+1);

  while(q--){
      ll t;
      cin>>t;
      if(t==2){
          ll l,r;
          cin>>l>>r;
          l--,r--;
          cout<<bit.query(l,r+1)<<endl;
      }
      else{
          ll x,y;
          cin>>x>>y;
          x--;
          ll ind=*st.lower_bound(x);
          while(ind<y){
              ll prev=v[ind];
              v[ind]=prime[v[ind]];
              bit.update(ind,v[ind]-prev);
              if(v[ind]<=2) st.erase(ind);
              ind=*st.lower_bound(ind+1);
          }
      }
  }

}



int main()
{ 
    fast_io;
    
    int _=1;
    // cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   