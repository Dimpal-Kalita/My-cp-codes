/*
    Trilasha Mazumder
*/

#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA




//0-> obs
void solve(){
    ll h,w;
    cin>>h>>w;
    pll s,e;
    vector<vector<ll>> v(h,vector<ll>(w));
    map<pll,ll> mp;
    fr(i,h){
        fr(j,w){
            char c;
            cin>>c;
            if(c=='#'){
                v[i][j]=0;
            }else{
                v[i][j]=1;
            }
            if(c=='S'){
                s={i,j};
            }
            if(c=='T'){
                e={i,j};
            }
        }
    }
    ll n;
    cin>>n;
    fr(i,n){
        ll x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        mp[{x,y}]=z;
    }
    if(mp[s]==0){
        cout<<"No"<<endl;
        return;
    }
    ll ok=0;
    queue<pair<ll,pll>> pq;
    pq.push({mp[s],s});
    vector<vector<ll>> dp(h+1,vector<ll>(w+1,-1));
    while(!pq.empty()){
        auto [c,curr]=pq.front();
        pq.pop();
        if(curr==e){
            ok=1;
            break;
        }
        ll x=curr.ff;
        ll y=curr.ss;
        c=max(c,mp[{x,y}]);
        if(dp[x][y]>=c || c<=0){
            continue;
        }   
        dp[x][y]=c;

        if(x<(h-1) && v[x+1][y]){
            if(dp[x+1][y]<(c-1)){
                pq.push({c-1,{x+1,y}});
            }
        }
        if(x>0 && v[x-1][y]){
            if(dp[x-1][y]<(c-1)){
                pq.push({c-1,{x-1,y}});
            }   
        }
        if(y<(w-1) && v[x][y+1]){
            if(dp[x][y+1]<(c-1)){
                pq.push({c-1,{x,y+1}});
            }
        }
        if(y>0 && v[x][y-1]){
            if(dp[x][y-1]<(c-1)){
                pq.push({c-1,{x,y-1}});
            }
        }
    }
    cout<<((ok)?"Yes":"No")<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
