/**
 * 
 * author: Dimpal Kalita
 * date: 20/05/2023 17:33:47
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
using vi  = vector<int>;





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




ll n,m;
vector<string>s;

void dk(){
     cin>>n>>m;
     s.resize(n);
     rep(i,0,n){
         cin>>s[i];
     }
     // debug(s)
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(i+4 < n && s[i][j] == 's' && s[i+1][j] == 'n' && s[i+2][j] == 'u' && s[i+3][j] =='k' && s[i+4][j] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i+k+1 << " " << j+1 << endl;
                    }
                    return;
               }
               if(j+4 < m && s[i][j] == 's' && s[i][j+1] == 'n' && s[i][j+2] == 'u' && s[i][j+3] =='k' && s[i][j+4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i+1 << " " << j+k+1 << endl;
                    }
                    return;
               }
               if(i+4 < n && j+4 < m && s[i][j] == 's' && s[i+1][j+1] == 'n' && s[i+2][j+2] == 'u' && s[i+3][j+3] =='k' && s[i+4][j+4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i+k+1 << " " << j+k+1 << endl;
                    }
                    return;
               }
               if(i+4 < n && j-4 >= 0 && s[i][j] == 's' && s[i+1][j-1] == 'n' && s[i+2][j-2] == 'u' && s[i+3][j-3] =='k' && s[i+4][j-4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i+k+1 << " " << j-k+1 << endl;
                    }
                    return;
               }
               if(i-4 >= 0 && j+4 < m && s[i][j] == 's' && s[i-1][j+1] == 'n' && s[i-2][j+2] == 'u' && s[i-3][j+3] =='k' && s[i-4][j+4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i-k+1 << " " << j+k+1 << endl;
                    }
                    return;
               }
               if(i-4 >= 0 && j-4 >= 0 && s[i][j] == 's' && s[i-1][j-1] == 'n' && s[i-2][j-2] == 'u' && s[i-3][j-3] =='k' && s[i-4][j-4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i-k+1 << " " << j-k+1 << endl;
                    }
                    return;
               }
               if(i-4 >= 0 && s[i][j] == 's' && s[i-1][j] == 'n' && s[i-2][j] == 'u' && s[i-3][j] =='k' && s[i-4][j] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i-k+1 << " " << j+1 << endl;
                    }
                    return;
               }
               if(j-4 >= 0 && s[i][j] == 's' && s[i][j-1] == 'n' && s[i][j-2] == 'u' && s[i][j-3] =='k' && s[i][j-4] == 'e' ){
                    for(int k = 0 ; k < 5 ; k ++){
                         cout << i+1 << " " << j-k+1 << endl;
                    }
                    return;
               }

          }
     }

}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}