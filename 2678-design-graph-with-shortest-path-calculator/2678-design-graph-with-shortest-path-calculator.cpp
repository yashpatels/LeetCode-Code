class Graph {
public:

    vector<vector<int>> adjList;
    int V;

    int minDistance(int dist[], bool sptSet[])
    {
    
        // Initialize min value
        int min = INT_MAX, min_index;
    
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
    
        return min_index;
    }

    Graph(int n, vector<vector<int>>& edges) {
        V=n;
        for (int i=0; i<n; i++) {
            vector<int> temp;
            for (int j=0; j<n; j++) {
                temp.push_back(0);
            }
            adjList.push_back(temp);
        }    

        for (int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]][edges[i][1]]=edges[i][2];
        }

    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]][edge[1]]=edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        int dist[V];
        bool sptSet[V];
       
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        
        dist[node1] = 0;
        for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)

            if (!sptSet[v] && adjList[u][v]
                && dist[u] != INT_MAX
                && dist[u] + adjList[u][v] < dist[v])
                dist[v] = dist[u] + adjList[u][v];
        }

        if (dist[node2] == INT_MAX) return -1;
        else return dist[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */