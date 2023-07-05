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





ll ha,wa,hb,wb,hx,wx;
vector<string> a(30),b(30),c(30);




// Function to merge two grids
std::vector<std::string> mergeGrids(const std::vector<std::string>& grid1, const std::vector<std::string>& grid2, int i1, int j1, int i2, int j2) {
    // Check if the indices are within the grid bounds
    int rows1 = grid1.size();
    int cols1 = grid1[0].size();
    int rows2 = grid2.size();
    int cols2 = grid2[0].size();

   
    // Calculate the maximum number of rows and columns needed for the merged grid
    int maxRows = std::max(rows1 - i1, rows2 - i2);
    int maxCols = std::max(cols1 - j1, cols2 - j2);

    // Create the merged grid
    std::vector<std::string> mergedGrid(maxRows+10, std::string(maxCols+10, '.'));

    // Merge the grids
    for (int r = 0; r < maxRows; ++r) {
        if (r + i1 < rows1 && r + i2 < rows2) {
            mergedGrid[r].replace(0, cols1 - j1, grid1[r + i1].substr(j1));
            mergedGrid[r].replace(cols1 - j1, maxCols, grid2[r + i2].substr(j2));
        } else if (r + i1 < rows1) {
            mergedGrid[r] = grid1[r + i1].substr(j1);
        } else if (r + i2 < rows2) {
            mergedGrid[r] = grid2[r + i2].substr(j2);
        }
    }

    return mergedGrid;
}

bool merge(ll i1, ll j1, ll i2,ll j2){
     vector<string> temp=mergeGrids(a,b,i1,j1,i2,j2);
     debug(temp);
     return 0;
}


void dk(){
     cin>>ha>>wa;
     rep(i,0,ha) cin>>a[i];
     cin>>hb>>wb;
     rep(i,0,hb) cin>>b[i];
     cin>>hx>>wx;
     rep(i,0,hx) cin>>c[i];
     mergeGrids(a,b,0,0,0,0);
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