#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define e "\n"
#define spc " "

void openfiles(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}


ll solve(){
	int n;
	cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a.begin(),a.end());
	for(int k=n;k>=1;k--){
		int cnt=0;
		int temp=1;
		for(int i=k-1;i<n;i++){
			if(a[i]<=temp) 
			{
				cnt++;
				temp++;
			}
		}
		if(cnt>=k) return k;
	}
	return (ll)0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//openfiles();
	int t=1; 
	cin>>t;
	while(t--){
		auto x=solve();
		cout<<x<<e;	
	}
	return 0;
}


