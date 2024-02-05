#include<bits/stdc++.h>
using namespace std;


/*---------------------------- Debugging Template starts---------------------------------*/
#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif
/*---------------------------- Debugging Template ends---------------------------------*/



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    debug(v);
}