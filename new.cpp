#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>>& graph, int platform, unordered_set<int>& visited, int depth, int& count) {
    // Base case: reached the desired depth
    if (depth == 0) {
        count++;
        return;
    }

    // Explore unvisited neighbors
    for (int neighbor : graph[platform]) {
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            dfs(graph, neighbor, visited, depth - 1, count);
            visited.erase(neighbor);
        }
    }
}

int maximum_new_pavements(int N, int M, vector<pair<int, int>>& connections) {
    // Step 1: Create adjacency list representation of the graph
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int A = connections[i].first;
        int B = connections[i].second;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    // Step 2: Initialize variables
    int maxPavements = 0;

    // Step 3: Iterate through each pair of platforms
    for (int x = 1; x <= N; x++) {
        unordered_set<int> visited;
        visited.insert(x);

        // Perform DFS from platform x with a depth limit of 3
        int count = 0;
        dfs(graph, x, visited, 3, count);
        maxPavements += count;
    }

    // Step 4: Return the maximum number of new pavements
    return maxPavements;
}

int main() {
    // Example usage
    int N;  // Number of platforms
    int M;  // Number of pavements
    cin>>N>>M;
    vector<pair<int, int>> connections;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        connections.push_back({u,v});
    }
    int maxPavements = maximum_new_pavements(N, M, connections);
    cout << "Maximum number of new pavements Alice can add: " << maxPavements << endl;

    return 0;
}