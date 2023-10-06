class Solution {
    int[][] graph;
    public int findCircleNum(int[][] isConnected) {

        graph = isConnected;    
        int noOfCities = isConnected[0].length;

        int noOfProvince=0;

        boolean[] visited = new boolean[noOfCities];

        for (int i=0; i<visited.length; i++){
            if (!visited[i]){
                noOfProvince++;
                dfs(i, visited);
            }
        }
        return noOfProvince;
    }

    public void dfs(int node, boolean[] visited){
        visited[node] = true;

        for (int i=0; i<graph[node].length; i++){
            if (graph[node][i]==1 && !visited[i]){
                dfs(i, visited);
            }
        }
    }
}