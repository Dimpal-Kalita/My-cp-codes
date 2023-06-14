/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 10:21:22
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


int LCS(vector<int>& firstArr,
        vector<int>& secondArr)
{
 
    unordered_map<int, int> mp;
    for (int i = 0; i < firstArr.size(); i++) {
        mp[firstArr[i]] = i + 1;
    }
    vector<int> tempArr;
 
    for (int i = 0; i < secondArr.size(); i++) {
 
        // If current element exists in the Map
        if (mp.find(secondArr[i]) != mp.end()) {
 
            tempArr.push_back(mp[secondArr[i]]);
        }
    }
    vector<int> tail;
    tail.push_back(tempArr[0]);
    for (int i = 1; i < tempArr.size(); i++) {
 
        if (tempArr[i] > tail.back())
            tail.push_back(tempArr[i]);
 
        else if (tempArr[i] < tail[0])
            tail[0] = tempArr[i];
 
        else {
            auto it = lower_bound(tail.begin(),
                                  tail.end(),
                                  tempArr[i]);
            *it = tempArr[i];
        }
    }
    return (int)tail.size();
}

void dk(){
     ll n;
     cin>>n;
     vi v1(n), v2(n);
     inp(v1);
     inp(v2);
     // cout<<LCS(v1,v2)<<endl;
     cout<<2*(n-LCS(v1,v2))<<endl;
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