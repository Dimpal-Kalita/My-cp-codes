/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 18:38:38
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

ll n , m; 
vector<vector<char>> grid;
ll cntrecur( ll x , ll y){
    ll ret =md, cnt = 0;
    ll X = x , Y = y;
    while(x < n && y < m && grid[x][y] == '#'){
        cnt++;
        x++;y++;
    }
    cnt--;
    ret = min(ret , cnt);
    cnt = 0;
    x = X , y = Y;
    while(x < n && y >= 0 && grid[x][y] == '#'){
        cnt++;
        x++;y--;
    }
    cnt--;
    ret = min(ret , cnt);
    cnt = 0;
    x = X , y = Y;
    while(x >= 0 && y < m && grid[x][y] == '#'){
        cnt++;
        x--;y++;
    }
    cnt--;
    ret = min(ret , cnt);
    cnt = 0;
    x = X , y = Y;
    while(x >= 0 && y >= 0 && grid[x][y] == '#'){
        cnt++;
        x--;y--;
    }
    cnt--;
    ret = min(ret , cnt);
    cnt = 0;
    x = X , y = Y;
    return ret;
}


void dk()
{
   
   cin >> n >> m;
   grid.resize(n , vector<char> (m));
   for(int i = 0 ; i < n ; i ++){
    for(int j = 0 ; j < m ; j ++){
        cin >> grid[i][j];
    }
   }
   vl cnt(min(n , m)+1);
   for(int i = 0 ; i < n ; i ++){
    for(int j = 0 ; j < m ;j ++){
        if(grid[i][j] == '#'){
            ll tmp = cntrecur(i , j);
            cnt[tmp]++;
        }
    }
   }
   for(int i = 1 ; i <= min(n , m) ; i ++){
    cout << cnt[i] << " ";
   }
   cout << endl;

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