class Solution {

    List<List<Integer>> roomList;
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        roomList = rooms;

        boolean[] visited = new boolean[rooms.size()];

        // visited[0] = true;
        DFS(0, visited);

        System.out.println(visited);

        for (int i=0; i<visited.length; i++){
            if (visited[i]==false){
                return false;
            }
        }
        return true;
    }

    void DFS(int x, boolean visited[]){
        visited[x] = true;
        for (int i=0; i<roomList.get(x).size(); i++){
            if (!visited[roomList.get(x).get(i)]){
                DFS(roomList.get(x).get(i), visited);
            }
        }
    }
}