#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> ps(n+1, 0);
    int count=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='D'&& s[i+1]=='K'){
            count++;
        }
        ps[i+1]=count;
    }
    ps[n]=count;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<ps[r-1]-ps[l-1]<<endl;
    }
    return 0;
}
