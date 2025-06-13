class Solution {
#define P pair<long long,int>    
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        int mod = 1e9 + 7;
        vector<long long> dist(n, 1e18);
        vector<int> paths(n, 0);
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<pair<int, int>>> adj(n);

        for (const auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        dist[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; // Optimization

            for (const auto &edge : adj[node]) {
                int newnode = edge.first;
                int newtime = edge.second;

                if (time + newtime < dist[newnode]) {
                    dist[newnode] = time + newtime;
                    paths[newnode] = paths[node];
                    pq.push({dist[newnode], newnode});
                } else if (time + newtime == dist[newnode]) {
                    paths[newnode] = (paths[newnode] + paths[node]) % mod;
                }
            }
        }
        return paths[n - 1] % mod;
    }
};
