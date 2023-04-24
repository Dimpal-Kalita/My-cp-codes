#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, dp[N], in_degree[N], out_degree[N], danger[N];
vector<int> adj[N];

void defeat_all_monsters() {
    // Perform topological sort
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
            if (dp[u] >= danger[v]) {
                dp[v] = max(dp[v], dp[u] + 1);
            }
        }
    }
    // Check if all monsters can be defeated
    bool possible = true;
    for (int i = 1; i <= n; i++) {
        cout<<dp[i]<<" ";
        if (dp[i] < danger[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> danger[i];
            adj[i].clear();
            dp[i]=0;
        }

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            in_degree[v]++;
            out_degree[u]++;
        }
        // cout<<n<<" ";
        defeat_all_monsters();
    }
    return 0;
}
