#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    map<string, vector<pair<int,int>>> mp;

    int t, m;
    cin>>t>>m;
    while(t--){
        int id;
        cin>>id;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            int val;
            cin>>s>>val;
            mp[s].pb({id, val});
        }
    }
    while(m--){
        int n;
        cin>>n;
        map<int,int> temp;

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(auto it:mp[s]){
                temp[it.F]+=it.S;
            }
        }

        vector<pair<int,int>> ans;
        for(auto it:temp){
            ans.pb({it.S,-it.F});
        }
        sort(ans.begin(), ans.end(), greater<pair<int,int>>());
        if(ans.size()==0){
            cout<<-1;
            if(m>0) cout<<"\n";
            continue;
        }
        int sz= min(10, (int)ans.size());
        for(int i=0;i<sz;i++){
            cout<<-ans[i].S;
            if(i<sz-1){
                cout<<" ";
            }
        }
        if(m>0) cout<<"\n";

    }

    return 0;
}