#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1e18
#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>




void solve(){
    ll n, m;
    cin>>n>>m;
    ll x= sqrt(m);

    if(m%n==0){
        cout<<0<<endl;
        return;
    }
    ll mn=1e9;
    for(int i=1;i<=x+1;i++){
        ll sq= (((m-1)/i) +1)*i;
        if(n>=(sq/i) && sq>=m) mn= min(mn,sq-m + n-(sq/i));
        if(n>=i && sq>=m) mn= min(mn, sq-m+n-i);
    }
    cout<<mn<<endl;
}






signed main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    for(int i = 0 ; i < t; i ++){
        solve();
    }
}