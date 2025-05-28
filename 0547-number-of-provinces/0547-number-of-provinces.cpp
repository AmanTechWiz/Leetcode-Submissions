class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        int count = 0;
        vector<vector<int>> list(V);
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                visited[i] = 1;
                bfs(i, visited, list);
            }
        }

        return count;
    }

    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int element = q.front();
            q.pop();

            for (int vertex : adj[element]) {
                if (!visited[vertex]) {
                    visited[vertex] = 1;
                    q.push(vertex);
                }
            }
        }
    }
};
