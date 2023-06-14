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
    string s; cin >> s;
    int n = s.length();
    vector<int> there(5,0);
    vector<vector<int>> add(n + 1,vector<int> (5)),sub(n + 1,vector<int> (5));
    int cnt = 0;
    for(int i=n-1;i>=0;i--){
        int x = s[i] - 'A';
        int ok = 1;
        for(int j=x+1;j<5;j++){
            if(there[j]){
                ok = 0;
                break;
            }
        }
        if(ok) {
            cnt += pow(10,x);
            add[i+1][x]++;
        }
        else {
            cnt -= pow(10,x);
            sub[i+1][x]++;
        }
        there[x] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++) add[i][j] += add[i-1][j];
    }
    int ans = cnt;
    vector<vector<int>> wh(5),store(n + 1,vector<int> (5));
    for(int i=n;i>=1;i--){
        int x = s[i - 1] - 'A';
        int ok = 0;
        int idx = -1;
        for(int j=x+1;j<5;j++){
            ok += wh[j].size();
            if(wh[j].size() > 0) {
                idx = wh[j][0];
            }
        }
        if(ok == 1){
            if(idx > -1) store[idx][x]++;
        }
        wh[x].push_back(i);
    }
    there = vector<int> (5,0);
    for(int i=n;i>=1;i--){
        int x = s[i - 1] - 'A';
        int ad = 0;
        for(int j=x-1;j>=0;j--){
            if(store[i][j] == 0) continue; 
            ad += 2 * store[i][j] * pow(10,j);
            ans = max(ans,ad + cnt - (int)pow(10,x) + (int)pow(10,j));
        }
        int sub = 0;
        int ok = 1;
        for(int j=x+1;j<5;j++){
            if(there[j]){
                ok = 0;
                break;
            }
        }
        if(ok) sub += pow(10,x);
        else sub -= pow(10,x);
        for(int j=x+1;j<5;j++){
            sub += pow(10,j) * add[i-1][j-1];
            int extra = 0;
            for(int k=j+1;k<5;k++){
                if(there[k]){
                    extra = -pow(10,j);
                    break;
                }
            }
            if(!extra) extra = pow(10,j);
            ans = max(ans,cnt - sub + extra);
        }
        there[x] = 1;
    }
    cout << ans << '\n';
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