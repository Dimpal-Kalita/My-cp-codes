/**
 * 
 * author: Dimpal Kalita
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




void dk(){
     string s;
     cin>>s;
     stack<int>st;
     int plus=0,minus=0;
     bool sorted=1;
     int last=0,ct=0;
     map<ll,ll>cnt;
     rep(_,0,sz(s)){
           char c=s[_];
           if(c=='+'){
               st.push(2);
               ct++;
           }
           if(c=='-'){
               if(st.size()){
                    if(st.top()==0){
                         cnt[0]--;
                    }
                    st.pop();
               }
               last--;
               ct--;
           }
           if(c=='1'){
               int ct=0;
               if(cnt[0]){
                    cout<<"NO"<<endl;
                    return;
               }
               stack<int>temp;
               while(st.size() and st.top()==2){
                    st.pop();
                    temp.push(1);
               }
               while(!temp.empty()){
                    st.push(1);
                    temp.pop();
               }
           }
           if(c=='0'){
               if(ct<2 || (st.size() and st.top()==1)){
                    cout<<"NO"<<endl;
                    return;
               }
               if(cnt[0]){
                    continue;
               }
               if(st.size() and st.top()==2){
                    st.pop();
                    st.push(0);  
                    cnt[0]++;
               }
           }
          //  stack<int>temp=st;
          //  while(!temp.empty()){
          //      cerr<<temp.top()<<" ";
          //      temp.pop();
          //  }
          //  cerr<<endl;
     } 
     cout<<"YES"<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}