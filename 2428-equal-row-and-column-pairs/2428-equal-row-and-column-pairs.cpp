class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        unordered_map<string, int> map;
        int cnt=0;

        int j=0;
        while (j < grid.size()){
            string temp1;
            for (int i=0; i<grid.size(); i++){
                temp1+= std::to_string(grid[i][j]);
                temp1+="-";
            }
            ++map[temp1];
            j++;
        }
        j=0;
        while (j < grid.size()){
            string temp1;
            for (int i=0; i<grid.size(); i++){
                temp1+= std::to_string(grid[j][i]);
                temp1+="-";
            }
            if (map.find(temp1) != map.end()){
                cout << temp1 << "\n";
                cnt+=map[temp1];
            }
            j++;
        }
        return cnt;
    }
};