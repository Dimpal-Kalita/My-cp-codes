// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using pii = pair<int,int>;
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using vi  = vector<int>;



void dk(){
    string s;
    cin>>s;
    ll ct=1, n=s.length(), mx=1;

    if(count(all(s),'1')==0){
        cout<<0<<endl;
        return;
    }
    if(count(all(s),'1')==n){
        cout<<n*n<<endl;
        return;
    }

    for(int i=0;i<2*n-1;i++){
        int ii=i%n, ii1=(i+1)%n;
        if(s[ii]=='1' and s[ii1]=='1') ct++;
        else {
            mx= max(ct,mx);
            ct=1;
        }
    }

    ll ans=1;

    for(int i=1;i<mx;i++){
        ans=max(ans,(mx-i)*(i+1));
    }

    cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}