class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int col = 1;
        vector<vector<int>> ans;
        for (int i=0; i<=rowIndex; i++){
            vector<int> singleRow;
            for (int j=0; j<col; j++){
                if (j==0 || j==col-1) singleRow.push_back(1);
                else {
                    singleRow.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            col++;
            ans.push_back(singleRow);
        }
        return ans[rowIndex];
    }
};