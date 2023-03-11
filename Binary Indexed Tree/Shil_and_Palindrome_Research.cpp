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


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
struct BIT{
    vector<ll> bit;
    vector<vector<ll>> btcnt;
    ll n;
    BIT(ll n){
        this->n=n;
        bit.assign(n+1,0);
        btcnt.assign(n+1, vector<ll>(26, 0));
    }
    vector<ll> calc(ll r){
        vector<ll> ret(26, 0);
        for(;r;r-=r&-r){
            for(int i=0;i<26;i++){
                ret[i]+=btcnt[r][i];
            }
        }
        return ret;
    }
    vector<ll> sum(ll l,ll r){
        vector<ll> ret(26, 0);
        for(;r;r-=r&-r){
            for(int i=0;i<26;i++){
                ret[i]+=btcnt[r][i];
            }
        }
        l--;
        for(;l;l-=l&-l){
            for(int i=0;i<26;i++){
                ret[i]-=btcnt[l][i];
            }
        }

        return ret;
    }
    void add(ll idx,char cur){
        for(;idx<=n;idx+=idx&-idx){
            btcnt[idx][cur-'a']++;
        }
    }
    void add(ll idx,char cur, char prev){
        for(;idx<=n;idx+=idx&-idx){
            btcnt[idx][cur-'a']++;
            btcnt[idx][prev-'a']--;
        }
    }
};


void dk(){
      ll n, k;
      cin>>n>>k;
      string s;
      cin>>s;
      BIT bit(n);
      for(ll i=1;i<=n;i++){
         bit.add(i, s[i-1]);
      }
      while(k--){
        ll v;
        cin>>v;
        if(v==1){
            ll idx;
            char c;
            cin>>idx>>c;
            bit.add(idx, c, s[idx-1]);
            s[idx-1]=c;
        }
        else{
            ll l, r;
            cin>>l>>r;
            vector<ll> cnt=bit.sum(l, r);
            ll odd=0;
            for(auto it:cnt){
                if(it%2) odd++;
            }
            // debug(cnt);
            if(odd==0 && (r-l+1)%2 == 0) cout<<"yes"<<endl;
            else if(odd==1 && (r-l+1)%2 == 1) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
      }
      


}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}