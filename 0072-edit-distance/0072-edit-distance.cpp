class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()][word2.size()];
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();

        bool found = false;
        if (word1[0] == word2[0]){
            dp[0][0] = 0;
            found = true;
        } else {
            dp[0][0] = 1;
        }

        for (int i=1; i<word2.size(); i++) {
            if (!found && word2[i] == word1[0]) {
                dp[0][i] = dp[0][i-1];
                found = true;
            } else {
                dp[0][i] = dp[0][i-1]+1;
            }
        }

        found = false;
        if (word1[0] == word2[0]){
            dp[0][0] = 0;
            found = true;
        } else {
            dp[0][0] = 1;
        }

        for (int i=1; i<word1.size(); i++) {
           if (!found && word1[i] == word2[0]) {
                dp[i][0] = dp[i-1][0];
                found = true;
            } else {
                dp[i][0] = dp[i-1][0]+1;
            }
        }


        for (int i=1; i<word1.size(); i++) {
            found = false;
            for (int j=1; j<word2.size(); j++) {
                int minVal = min (dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                if (!found && word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                    // found=true;
                } else {
                    dp[i][j] = minVal+1;
                }
            }
        }

        // for (int i=0; i<word1.size(); i++) {
        //     for (int j=0; j<word2.size(); j++) {
        //         cout << dp[i][j] << "  ";
        //     }
        //     cout << endl;
        // }
        return dp[word1.size()-1][word2.size()-1];
    }
};