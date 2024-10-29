class Solution {
public:
    // int ans = 0;
    int rows, cols;
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (j == grid[0].size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // cout << i << " " << j << endl;
        int x1=0, x2=0, x3=0;
        if (j<cols-1) {
            if (i>0 && grid[i][j]<grid[i-1][j+1]) {
                x1 = 1+helper(i-1, j+1, grid, dp);
            }

            if (i<rows-1 && grid[i][j]<grid[i+1][j+1]) {
                x2 = 1+helper(i+1, j+1, grid, dp);
            }

            if (grid[i][j] < grid[i][j+1]) {
                x3=1+helper(i, j+1, grid, dp);
            }
        }
        // cout << x1 << " " << x2 << " " << x3 << endl;
        return dp[i][j]=max(x1, max(x2, x3));
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int ans=-1;
        for (int i=0; i<rows; i++) {
            // cout << "here\n";
            ans = max(ans, helper(i, 0, grid, dp));
        }
        return ans;
    }
};