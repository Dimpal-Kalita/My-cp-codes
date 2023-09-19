/*
    Author: Vasanth Reddy
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}
template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v){for (auto &it : v) cout << it << ' '; return ostream;}

void solveIt(){
    int n,q; cin >> n >> q;
    int x = 1;
    while(n >= x) x *= 2;
    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r;
        int ans = (r + 1) / x - (l - 1) / x;
        ans *= 2;
        if((r + 1) % x == 0) --ans;
        if(l % x == 0) --ans;
        cout << ans << '\n';
    }
}

#undef int
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tcs=1;
    cin >> tcs;
    for(int i=1;i<=tcs;i++){
        solveIt();
    }
}