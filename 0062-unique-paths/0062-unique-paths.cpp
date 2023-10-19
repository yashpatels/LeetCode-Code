class Solution {
public:
    int uniquePaths(int rows, int column) {
        int dp[rows][column];

        dp[0][0] = 1;

        for (int i=1; i<rows; i++) dp[i][0]=1;
        for (int i=1; i<column; i++) dp[0][i]=1;

        for (int i=1; i<rows; i++){
            for (int j=1; j<column; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[rows-1][column-1];

    }   
};