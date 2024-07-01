class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> x = heights;
        sort(heights.begin(), heights.end());
        int cnt=0;
        for (int i=0; i<x.size(); i++) {
            if (x[i]!=heights[i]) cnt++;
        }
        return cnt;
    }
};