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

const int N=3001;
uitset<N>bt[N];
vector<string>v(N);
void dk(){
    int n;
    cin>>n;
    rep(i,0,n){
        string s;
        cin>>s;
        v[i]=s;
        rep(j,i+1,n){
            if(s[j]=='1'){
                bt[i][j]=1;
            }
        }
    }
    ll ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
           if(v[i][j]=='1') ans+= (bt[i]&bt[j]).count();
        }
    }
    cout<<ans<<endl;

}



int main()
{ 
    fast_io;

    int n=1;
    //cin>>n;
    for(int i=0;i<n;i++){
        dk();
    }
    return 0;
}

