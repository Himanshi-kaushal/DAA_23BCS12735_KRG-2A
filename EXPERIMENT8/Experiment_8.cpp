#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v w) 0-based indices:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<ll> dist(V, INF);
    vector<int> parent(V, -1);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});
    clock_t start = clock();
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    clock_t end = clock();

    cout << "Vertex  Distance  Path(from " << src << ")\n";
    for (int v = 0; v < V; ++v) {
        if (dist[v] == INF) {
            cout << v << "      " << "INF" << "       " << "No path\n";
            continue;
        }
        cout << v << "      " << dist[v] << "       ";
        vector<int> path;
        int cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        for (int i = (int)path.size() - 1; i >= 0; --i) {
            cout << path[i];
            if (i) cout << "->";
        }
        cout << "\n";
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken (Dijkstra main loop): " << time_taken << " seconds\n";
    return 0;
}

/*Input:
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v w) 0-based indices:
0 1 10
0 3 5
1 2 1
3 1 3
3 2 8
3 4 2
Enter source vertex: 0

Output:
Vertex  Distance  Path(from 0)
0      0       0
1      8       0->3->1
2      9       0->3->1->2
3      5       0->3
4      7       0->3->4
Time taken (Dijkstra main loop): 0.000009 seconds

Time Complexity:
Time: O((V + E) log V) which is typically written as O(E log V) for connected sparse graphs using a binary heap priority queue.
Space: O(V + E) for adjacency list plus O(V) for dist and parent arrays.*/
