// 2112048
// Dimpal Kalita
// CSE sec A

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
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


map<char,ll> fir= {{'H', 1},{'D',1},{'C',1},{'S',1}};
map<char, ll> sec= {{'A', 1}, {'2', 1}, {'3', 1}, {'4', 1},{'5', 1},{'6', 1},{'7', 1},{'8', 1},{'9', 1},{'T', 1},{'J', 1}, {'Q', 1}, {'K', 1}};

void dk(){
    ll n;
    cin>>n;
    string s[n];
    fr(i, n) cin>>s[i];

    for(ll  i=0;i<n;i++){
        if(!fir.count(s[i][0])){
            cout<<"No"<<endl;
            return;
        }
        if(!sec.count(s[i][1])){
            cout<<"No"<<endl;
            return;
        }
    }

    for(ll i=0;i<n;i++){
         for(ll j=00;j<n;j++){
            if(i==j) continue;

            if(s[i]==s[j]){
                cout<<"No"<<endl;
                return;
            }
         }
    }  
    cout<<"Yes"<<endl;
      


}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
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