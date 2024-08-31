class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // vector<vector<double>> adj(n, vector<double>(n));
        
        vector<double> ans(n, 0);
        vector<bool> visited(n, false);

        priority_queue<pair<double,int>> pq;

        pq.push(make_pair(1, start_node));
        ans[start_node]=1;


        vector<vector<pair<int, double>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        while (!pq.empty()) {

            int vertex = pq.top().second;
            int prob = pq.top().first;

            // cout << "new " << vertex << " " << prob << endl;

            visited[vertex]=true;
            pq.pop();

            for (auto& neighbor : adj[vertex]) {
                int next_vertex = neighbor.first;
                double edge_prob = neighbor.second;
                    // cout << "for " << i << endl;
                    // cout << adj[vertex][i] << " " << ans[vertex]*adj[vertex][i] << " " << ans[i] << endl;
                    if (!visited[next_vertex] && ans[vertex] * edge_prob > ans[next_vertex]) {
                    ans[next_vertex] = ans[vertex] * edge_prob;
                    pq.push({ans[next_vertex], next_vertex});
                }
            }

        }
        // cout << endl;
        // for (int i=0; i<n;i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << endl << endl;

        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans[end_node];
    }
};